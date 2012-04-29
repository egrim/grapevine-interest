#include "GrapevinePacket.h"

Register_Class(GrapevinePacket);

void GrapevinePacket::copy(const GrapevinePacket& other)
{
    this->payloadSize_var = other.payloadSize_var;
    this->summaries_var = other.summaries_var;
}

void GrapevinePacket::addContextSummary(ContextSummary summary)
{
    summaries_var[summary.getId()] = summary;
}

void GrapevinePacket::updatePacketLength() {
    int size(0);
    size += 4;                  // 4 bytes to store length of payload
    size += getPayloadSize();   // number of payload bytes

    size += 40;                 // 40 bytes for bloomier filter summary overhead

    ContextSummaryMap summaries = getSummaries();
    ContextSummaryMapIterator iter;
    for (iter=summaries.begin(); iter != summaries.end(); iter++) {
        ContextSummary summary = iter->second;
        size += 5 * summary.getNumContextItems() * 1.20; // 5 bytes per table entry * number of entries (with 20% more entries than context items)
    }

    setByteLength(size);
}




