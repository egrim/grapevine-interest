#ifndef INTERESTTRACKER_H_
#define INTERESTTRACKER_H_

#include <set>

#include "InterestSummary.h"

class InterestTracker {
protected:
    std::set<int> localInterestLabels;
    int hopLimit;
    simtime_t timeLimit;
    InterestSummary interestSummary;
    int numInterestSummaryBins;
public:
    void addLocalInterest(int label);
    int getHopLimit() const;
    simtime_t getTimeLimit() const;
    void setHopLimit(int hopLimit);
    void setTimeLimit(simtime_t timeLimit);
    void setNumInterestSummaryBins(int numInterestSummaryBins);
    bool contains(int label) const;

    InterestSummary getInterestSummaryToSend();
    void assimilateReceivedInterestSummary(const InterestSummary interest);
};

#endif /* INTERESTTRACKER_H_ */
