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

    contextManager.setHostId(getHostId());
    contextManager.setHopLimit(par("hopLimit").doubleValue());
    contextManager.setTimeLimit(par("timeLimit"));
    contextManager.setNumLocalContextItemsAvailable(par("numLocalContextItemsAvailable").doubleValue());
    contextManager.setNumContextItemsOfInterest(par("numContextItemsOfInterest").doubleValue());
    contextManager.setTrackInterest(par("trackInterest").boolValue());

    if (contextManager.getTrackInterest()) {
        contextManager.setNumInterestSummaryBins(par("numInterestSummaryBins").doubleValue());
    }

    beaconSendSocket.setOutputGate(gate("udpOut"));
    beaconSendSocket.bind(BEACON_PORT);
    beaconSendSocket.connect(beaconAddress, BEACON_PORT);

    beaconReceiveSocket.setOutputGate(gate("udpOut"));
    beaconReceiveSocket.bind(BEACON_PORT);
    beaconReceiveSocket.setCallbackObject(this, NULL);

    scheduleAt(beaconStartTime+par("beaconIntervalJitter").doubleValue(), &beaconTimer);
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
    pkt->setPayloadSize(par("payloadSize").doubleValue());

    contextManager.preparePacket(pkt);

    pkt->updatePacketLength();
    EV << "Packet prepared for sending" << endl;
    printPacket(pkt);
    beaconSendSocket.send(pkt);
}

void Grapevine::scheduleNextBeacon() {
    scheduleAt(simTime()+beaconInterval+par("beaconIntervalJitter").doubleValue(), &beaconTimer);
}

void Grapevine::socketDatagramArrived(int sockId, void *yourPtr, cMessage *msg, UDPControlInfo *ctrl) {
    GrapevinePacket *pkt = check_and_cast<GrapevinePacket *>(msg);
    printPacket(pkt, ctrl);
    contextManager.handlePacket(pkt);
}

void Grapevine::printPacket(GrapevinePacket *msg, UDPControlInfo *ctrl) {
    EV << msg << "  (" << msg->getByteLength() << " bytes)" << endl;
    EV << "Packet contents" << endl;
    EV << "   Payload size: " << msg->getPayloadSize() << endl;
    if (msg->getTrackInterest()) {
        EV << "   Tracking interest: true" << endl;
        EV << "      Labels: ";
        std::set<int> labels = msg->getInterest().debugInfo.labels;
        for (std::set<int>::const_iterator iter = labels.begin(); iter != labels.end(); iter++) {
            EV << *iter << " ";
        }
        EV << endl;
    } else {
        EV << "   Tracking interest: false" << endl;
    }

    ContextSummaryMap summaries = msg->getSummaries();
    if (summaries.size() > 0) {
        EV << "   " << "Context Summaries: true" << endl;
        for (ContextSummaryMapIterator iter = summaries.begin(); iter != summaries.end(); iter++) {
            EV << "      Context labels: ";
            ContextMap map = iter->second.debugGetContextSummary();
            for (std::map<int, int>::const_iterator iter2 = map.begin(); iter2 != map.end(); iter2++) {
                EV << iter2->first << " ";
            }
            EV << endl;
        }
    } else {
        EV << "   Context Summaries: false" << endl;
    }


    if (ctrl != NULL) {
        IPvXAddress srcAddr = ctrl->getSrcAddr();
        IPvXAddress destAddr = ctrl->getDestAddr();
        int srcPort = ctrl->getSrcPort();
        int destPort = ctrl->getDestPort();
        EV << srcAddr << " :" << srcPort << " --> " << destAddr << ":" << destPort << endl;
    }
}

int Grapevine::getHostId() {
    // TODO: this could be more robust
    int hostId;
    std::string path = getFullPath();
    std::stringstream host(path.substr(path.find("[")+1));
    host >> hostId;
    return hostId;
}
