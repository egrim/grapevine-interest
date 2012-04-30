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

#ifndef CONTEXTMANAGER_H_
#define CONTEXTMANAGER_H_

#include "omnetpp.h"

#include "InterestTracker.h"
#include "ContextSummary.h"
#include "GrapevinePacket.h"

class ContextManager {
protected:
    int hostId;
    int hopLimit;
    simtime_t timeLimit;

    bool trackInterest;
    InterestTracker interestTracker;

    ContextMap localContextMap;
    ContextSummaryMap receivedContextSummaries;
public:
    ContextManager() : hostId(0), hopLimit(0), timeLimit(0), trackInterest(false) { }
    void setHostId(int hostId);
    void setTrackInterest(bool trackInterest);
    void setHopLimit(int hopLimit);
    void setTimeLimit(simtime_t timeLimit);
    void setNumLocalContextItemsAvailable(int numLocalContextItemsAvailable);
    void setNumContextItemsOfInterest(int numContextItemsOfInterest);
    void setNumInterestSummaryBins(int numInterestSummaryBins);

    const bool getTrackInterest();
    const ContextMap getLocalContext() const;
    const ContextSummaryMap getReceivedContextSummaries() const;
    const ContextSummaryMap getSummariesToSend() const;

    void preparePacket(GrapevinePacket *pkt);
    void handlePacket(GrapevinePacket const *pkt);
};

#endif /* CONTEXTMANAGER_H_ */
