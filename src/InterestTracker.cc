#include "InterestTracker.h"

void InterestTracker::addLocalInterest(int label) {
    localInterestLabels.insert(label);
}

int InterestTracker::getHopLimit() const
{
    return hopLimit;
}

simtime_t InterestTracker::getTimeLimit() const
{
    return timeLimit;
}

void InterestTracker::setHopLimit(int hopLimit)
{
    this->hopLimit = hopLimit;
}

void InterestTracker::setTimeLimit(simtime_t timeLimit)
{
    this->timeLimit = timeLimit;
}

bool InterestTracker::contains(int label) const {
    return interestSummary.contains(label);
}

InterestSummary InterestTracker::getInterestSummaryToSend() {
    interestSummary.updateToTime(simTime());

    InterestSummary outgoing(interestSummary);

    std::set<int>::const_iterator iter;
    for (iter = localInterestLabels.begin(); iter != localInterestLabels.end(); iter++) {
        outgoing.addInterest(*iter, hopLimit, timeLimit);
    }

    return outgoing;
}

void InterestTracker::setNumInterestSummaryBins(int numInterestSummaryBins)
{
    this->numInterestSummaryBins = numInterestSummaryBins;
    interestSummary = InterestSummary(simTime(), numInterestSummaryBins);
}

void InterestTracker::assimilateReceivedInterestSummary(const InterestSummary receivedInterestSummary) {
    interestSummary.merge(receivedInterestSummary);
}
