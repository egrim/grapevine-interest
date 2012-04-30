#include "InterestSummary.h"

bool InterestSummary::contains(int label) const
{
    return hopLimitFilter.probably_contains(label) &&
           timeLimitFilter.probably_contains(label);
}

void InterestSummary::addInterest(int label, int hopLimit, simtime_t timeLimit)
{
    hopLimitFilter.max(label, hopLimit);
    timeLimitFilter.max(label, timeLimit.dbl());

    debugInfo.labels.insert(label);
}

void InterestSummary::recordArrivalTime(const simtime_t timestamp)
{
    relativeTimestamp = timestamp;
}

void InterestSummary::updateToTime(const simtime_t timestamp)
{
    if (timestamp > relativeTimestamp) {
        simtime_t delta = timestamp - relativeTimestamp;
        timeLimitFilter.decrementAll(delta.dbl());
    }
    relativeTimestamp = timestamp;
}

void InterestSummary::decrementHopLimit()
{
    hopLimitFilter.decrementAll(1);
}

void InterestSummary::merge(const InterestSummary summary)
{
    updateToTime(summary.getRelativeTime());
    hopLimitFilter.mergeMax(summary.hopLimitFilter);
    timeLimitFilter.mergeMax(summary.timeLimitFilter);

    debugInfo.labels.insert(summary.debugInfo.labels.begin(),
                            summary.debugInfo.labels.end());
}

simtime_t InterestSummary::getRelativeTime() const
{
    return relativeTimestamp;
}

int InterestSummary::getWireSize()
{
    return (hopLimitFilter.num_bins() * hopLimitFilter.bits_per_bin() + 7)/8;
}




