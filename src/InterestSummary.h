#ifndef INTERESTSUMMARY_H_
#define INTERESTSUMMARY_H_

#include "boost/bloom_filter/dynamic_counting_bloom_filter.hpp"

#include "omnetpp.h"

class InterestSummary : public cObject {
protected:
    simtime_t relativeTimestamp;

    boost::bloom_filters::dynamic_counting_bloom_filter<int, 4> hopLimitFilter;
    boost::bloom_filters::dynamic_counting_bloom_filter<int, 16> timeLimitFilter;

public:
    InterestSummary() { };
    InterestSummary(simtime_t relativeTimestamp, int numBins)
        : relativeTimestamp(relativeTimestamp),
          hopLimitFilter(numBins),
          timeLimitFilter(numBins) { };

    bool contains(int label) const;
    void addInterest(int label, int hopLimit, simtime_t timeLimit);

    void recordArrivalTime(const simtime_t timestamp);
    void updateToTime(const simtime_t timestamp);
    simtime_t getRelativeTime() const;

    void decrementHopLimit();

    void merge(const InterestSummary summary);

    int getWireSize();

    struct DebugInfo {
        std::set<int> labels;
    };

    DebugInfo debugInfo;
};

#endif /* INTEREST_SUMMARY_H_ */
