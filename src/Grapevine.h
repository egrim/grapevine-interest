#ifndef GRAPEVINE_H_
#define GRAPEVINE_H_

#include <map>

#include <UDPAppBase.h>
#include <UDPSocket.h>

#include "ContextSummary.h"

#define BEACON_PORT 4498

typedef std::map<int, ContextSummary> ContextSummaryMap;
typedef std::map<int, ContextSummary>::const_iterator ContextSummaryMapIterator;

class Grapevine: public UDPAppBase, public UDPSocket::CallbackInterface {
protected:
    double beaconStartTime;
    double beaconInterval;
    IPvXAddress beaconAddress;

    UDPSocket beaconSendSocket;
    UDPSocket beaconReceiveSocket;

    cMessage beaconTimer;

    ContextSummary myContextSummary;
    ContextSummaryMap receivedContextSummaries;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    virtual void sendBeacon();
    virtual void scheduleNextBeacon();

    virtual void socketDatagramArrived(int sockId, void *yourPtr, cMessage *msg, UDPControlInfo *ctrl);
    void printPacket(cPacket *msg, UDPControlInfo *ctrl);

    int getHostId();
    ContextSummaryMap getSummaries();
};

#endif /* GRAPEVINE_H_ */
