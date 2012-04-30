#include "GrapevinePacket.h"

Register_Class(GrapevinePacket);

void GrapevinePacket::addContextSummary(ContextSummary summary)
{
    summaries_var[summary.getId()] = summary;
}

void GrapevinePacket::setInterest(InterestSummary summary)
{
    GrapevinePacket_Base::setInterest(summary);
    setTrackInterest(true);
}

void GrapevinePacket::updatePacketLength() {
    int size = 0;
    size += 4;                  // 4 bytes to store length of payload
    size += getPayloadSize();   // number of payload bytes

    if (getTrackInterest()) {
        size += getInterest().getWireSize();
    }

    ContextSummaryMap summaries = getSummaries();
    ContextSummaryMapIterator iter;
    for (iter=summaries.begin(); iter != summaries.end(); iter++) {
        size += iter->second.getWireSize();
    }

    setByteLength(size);
}




