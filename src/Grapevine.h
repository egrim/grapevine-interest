#ifndef GRAPEVINE_H_
#define GRAPEVINE_H_

#include <map>

#include <UDPAppBase.h>
#include <UDPSocket.h>

#include "ContextManager.h"

#define BEACON_PORT 4498

class Grapevine: public UDPAppBase, public UDPSocket::CallbackInterface {
protected:
    double beaconStartTime;
    double beaconInterval;
    IPvXAddress beaconAddress;

    UDPSocket beaconSendSocket;
    UDPSocket beaconReceiveSocket;

    cMessage beaconTimer;

    ContextManager contextManager;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    virtual void sendBeacon();
    virtual void scheduleNextBeacon();

    virtual void socketDatagramArrived(int sockId, void *yourPtr, cMessage *msg, UDPControlInfo *ctrl);
    void printPacket(GrapevinePacket *msg, UDPControlInfo *ctrl=NULL);

    int getHostId();
};

#endif /* GRAPEVINE_H_ */
