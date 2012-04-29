#ifndef CONTEXTSUMMARY_H_
#define CONTEXTSUMMARY_H_

#include <omnetpp.h>


class ContextSummary: public cObject {
protected:
    int id;
    int numContextItems;
    int hopLimit;
    simtime_t timestamp;
public:
    int getHopLimit() const;
    int getId() const;
    int getNumContextItems() const;
    simtime_t getTimestamp() const;
    void setHopLimit(int hopLimit);
    void decrementHopLimit();
    void setId(int id);
    void setNumContextItems(int numContextItems);
    void setTimestamp(simtime_t timestamp);
};

#endif /* CONTEXTSUMMARY_H_ */
