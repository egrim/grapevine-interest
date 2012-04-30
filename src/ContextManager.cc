//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "omnetpp.h"

#include "ContextManager.h"
#include "ContextSummary.h"


const ContextMap ContextManager::getLocalContext() const
{
    return localContextMap;
}

const ContextSummaryMap ContextManager::getReceivedContextSummaries() const
{
    return receivedContextSummaries;
}

void ContextManager::setHostId(int hostId)
{
    this->hostId = hostId;
}

void ContextManager::setHopLimit(int hopLimit)
{
    this->hopLimit = hopLimit;
    this->interestTracker.setHopLimit(hopLimit);
}

void ContextManager::setTimeLimit(simtime_t timeLimit)
{
    this->timeLimit = timeLimit;
    this->interestTracker.setTimeLimit(timeLimit);
}

void ContextManager::setNumLocalContextItemsAvailable(int numLocalContextItemsAvailable)
{
    for (int i=0; i < numLocalContextItemsAvailable; i++)
        localContextMap[i] = i;
}

void ContextManager::setNumContextItemsOfInterest(int numContextItemsOfInterest)
{
    for (int i=0; i < numContextItemsOfInterest; i++) {
        interestTracker.addLocalInterest(i); // TODO: this should be randomly spread among available context item labels
    }
}

// TODO: should I be using pointers to avoid unnecessary copies of the summaries?
const ContextSummaryMap ContextManager::getSummariesToSend() const {
    ContextSummaryMap summaries;

    ContextSummaryMapIterator iter;
    for (iter=receivedContextSummaries.begin();
         iter != receivedContextSummaries.end();
         iter++) {
            ContextSummary summary = iter->second;
            if (summary.getHopLimit() > 0) {
                summaries[summary.getId()] = summary;
            }
    }


    if (trackInterest) {
        // Build a context summary only containing items known to be interesting
        ContextSummary interestingContext;
        ContextMap::const_iterator iter;
        EV << "Building interestingContext" << endl;
        for (iter = localContextMap.begin(); iter != localContextMap.end(); iter++) {
            EV << "Checking if local context with label " << iter->first << " is interesting: ";
            if (interestTracker.contains(iter->first)) {
                EV << " yup!" << endl;
                interestingContext.setContextItem(iter->first, iter->second);
            } else {
                EV << " nope!" << endl;
            }
        }

        if (interestingContext.getContextMap().size() > 0) {
            interestingContext.setId(hostId);
            interestingContext.setTimestamp(simTime());
            interestingContext.setHopLimit(hopLimit);
            summaries[hostId] = interestingContext;
        }

    } else {
        // Build summary using all local context
        ContextSummary localContext(localContextMap);
        localContext.setId(hostId);
        localContext.setTimestamp(simTime());
        localContext.setHopLimit(hopLimit);
        summaries[hostId] = localContext;
    }
    return summaries;
}

void ContextManager::setTrackInterest(bool trackInterest)
{
    this->trackInterest = trackInterest;
}

void ContextManager::preparePacket(GrapevinePacket *pkt)
{
    const ContextSummaryMap summaries = getSummariesToSend();
//    EV << "Summaries to send: " << summaries.size();
    ContextSummaryMapIterator iter;
    for (iter = summaries.begin(); iter != summaries.end(); iter++) {
        ContextSummary summary = iter->second;
        EV << "Adding context summary with id=" << summary.getId() << " to outgoing packet\n";
        pkt->addContextSummary(summary);
    }

    if (trackInterest) {
        pkt->setInterest(interestTracker.getInterestSummaryToSend());
    }
}

void ContextManager::setNumInterestSummaryBins(int numInterestSummaryBins)
{
    interestTracker.setNumInterestSummaryBins(numInterestSummaryBins);
}

const bool ContextManager::getTrackInterest()
{
    return trackInterest;
}

void ContextManager::handlePacket(const GrapevinePacket *pkt) {
    ContextSummaryMap summaries = pkt->getSummaries();
    ContextSummaryMapIterator iter;
    for (iter = summaries.begin(); iter != summaries.end(); iter++) {
        ContextSummary summary = iter->second;
        summary.decrementHopLimit();
        int id = summary.getId();
        if (id != hostId) {
            if (receivedContextSummaries.count(id) > 0) {
                ContextSummary existing = receivedContextSummaries[id];
                if (summary.getTimestamp() > existing.getTimestamp()) {
                    receivedContextSummaries[id] = summary;
                    EV << "Updating summary with id=" << id << endl;
                } else {
                    EV << "Discarding non-new summary with id=" << id << endl;
                }
            } else {
                receivedContextSummaries[id] = summary;
                EV << "Adding summary with id=" << id << endl;
            }
        }
    }

    if (trackInterest) {
        InterestSummary receivedInterestSummary = pkt->getInterest();
        receivedInterestSummary.recordArrivalTime(pkt->getArrivalTime());
        receivedInterestSummary.decrementHopLimit();

        interestTracker.assimilateReceivedInterestSummary(receivedInterestSummary);
    }
}




