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

#include <sstream>

#include "IPAddressResolver.h"

#include "Grapevine.h"
#include "GrapevinePacket.h"


Define_Module(Grapevine);

void Grapevine::initialize() {
    beaconStartTime = par("beaconStartTime");
    beaconInterval = par("beaconInterval");

    const char * beaconAddressString = par("beaconAddress");
    if (strstr(beaconAddressString,"Broadcast")!=NULL) {
        beaconAddress = IPAddress::ALLONES_ADDRESS;
    } else {
        beaconAddress = IPAddressResolver().resolve(beaconAddressString);
    }

    myContextSummary.setId(getHostId());
    myContextSummary.setNumContextItems((int)par("numLocalContextItemsAvailable"));
    myContextSummary.setHopLimit((int)par("hopLimit"));

    beaconSendSocket.setOutputGate(gate("udpOut"));
    beaconSendSocket.bind(BEACON_PORT);
    beaconSendSocket.connect(beaconAddress, BEACON_PORT);

    beaconReceiveSocket.setOutputGate(gate("udpOut"));
    beaconReceiveSocket.bind(BEACON_PORT);
    beaconReceiveSocket.setCallbackObject(this, NULL);

    scheduleAt(beaconStartTime+(double)par("beaconIntervalJitter"), &beaconTimer);
}

void Grapevine::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        sendBeacon();
        scheduleNextBeacon();
    } else if (beaconReceiveSocket.belongsToSocket(msg)) {
        beaconReceiveSocket.processMessage(msg);
    }
}

void Grapevine::sendBeacon() {
    GrapevinePacket *pkt = new GrapevinePacket("beacon");
    pkt->setPayloadSize((int)par("payloadSize"));
    pkt->setByteLength(100);
    ContextSummaryMap summaries = getSummaries();
    ContextSummaryMapIterator iter;
    for (iter = summaries.begin(); iter != summaries.end(); iter++) {
        ContextSummary summary = iter->second;
        if (summary.getHopLimit() > 0) {
            EV << "Adding context summary with id=" << summary.getId() << " to outgoing packet\n";
            pkt->addContextSummary(summary);
        }
    }

    beaconSendSocket.send(pkt);
    // TODO: stub
    //        GrapevinePacket *pkt = new GrapevinePacket("Beacon");
    //        // Size = 40 byte bloomier data structure overhead
    //        //      + 5 bytes per table entry * numTableEntries (with 20% more slots than context items)
    //        //      + 4 byte payload size indicator
    //        //      + payloadSize (allowed to vary - e.g.: uniform(100,200))
    //        pkt->setByteLength(40+5*numContextItems*1.20+4+(int)par("payloadSize"));
    //
    //        ContextKeys keys
    //        pkt->setContextMap(contextMap);
    //        beaconSendSocket.send(pkt);
}

void Grapevine::scheduleNextBeacon() {
    scheduleAt(simTime()+beaconInterval+(double)par("beaconIntervalJitter"), &beaconTimer);
}

void Grapevine::socketDatagramArrived(int sockId, void *yourPtr, cMessage *msg, UDPControlInfo *ctrl) {
    GrapevinePacket *pkt = check_and_cast<GrapevinePacket *>(msg);
    printPacket(pkt, ctrl);
    ContextSummaryMap summaries = pkt->getSummaries();
    ContextSummaryMapIterator iter;
    for (iter=summaries.begin(); iter != summaries.end(); iter++) {
        ContextSummary summary = iter->second;
        int id = summary.getId();
        if (id != getHostId()) {
            if (receivedContextSummaries.count(id) > 0) {
                // Already present, should we update?
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
}

void Grapevine::printPacket(cPacket *msg, UDPControlInfo *ctrl) {
    IPvXAddress srcAddr = ctrl->getSrcAddr();
    IPvXAddress destAddr = ctrl->getDestAddr();
    int srcPort = ctrl->getSrcPort();
    int destPort = ctrl->getDestPort();

    ev  << msg << "  (" << msg->getByteLength() << " bytes)" << endl;
    ev  << srcAddr << " :" << srcPort << " --> " << destAddr << ":" << destPort << endl;
}

// TODO: should I be using pointers to avoid unnecessary copies of the summaries?
ContextSummaryMap Grapevine::getSummaries() {
    ContextSummaryMap summaries;
    ContextSummaryMapIterator iter;
    for (iter=receivedContextSummaries.begin();
         iter != receivedContextSummaries.end();
         iter++) {
            ContextSummary summary = iter->second;
            summaries[summary.getId()] = summary;
    }

    // Update timestamp on my summary and include in list
    myContextSummary.setTimestamp(simTime());
    summaries[myContextSummary.getId()] = myContextSummary;
    return summaries;
}

int Grapevine::getHostId() {
    // TODO: this could be more robust
    int hostId;
    std::string path = getFullPath();
    std::stringstream host(path.substr(path.find("[")+1));
    host >> hostId;
    return hostId;
}
