package grapevine_interest;

import inet.applications.udpapp.UDPApp;

simple Grapevine like UDPApp
{
    parameters:
        double beaconStartTime @unit("s") = default(5s);
        double beaconInterval @unit("s") = default(1s);
        volatile double beaconIntervalJitter @unit("s") = default(uniform(-0.001s,0.001s));
        string beaconAddress = default("Broadcast");
        
        int numLocalContextItemsAvailable;
        int hopLimit;
        volatile int payloadSize;
        
    gates:
        input udpIn @labels(UDPControlInfo/up);
        output udpOut @labels(UDPControlInfo/down);
}
