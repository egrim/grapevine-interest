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
        int numInterestSummaryBins;
        int hopLimit;
        double timeLimit @unit("s");
        volatile int payloadSize;
        
        bool trackInterest = default(false);
        int numContextItemsOfInterest = default(numLocalContextItemsAvailable);
        
    gates:
        input udpIn @labels(UDPControlInfo/up);
        output udpOut @labels(UDPControlInfo/down);
}
