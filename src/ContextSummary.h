#ifndef CONTEXTSUMMARY_H_
#define CONTEXTSUMMARY_H_

#include <omnetpp.h>

typedef std::map<int, int> ContextMap;

class ContextSummary: public cObject {
protected:
    int id;
    int hopLimit;
    simtime_t timestamp;
    ContextMap context;
public:
    ContextSummary() { }
    ContextSummary(const ContextMap map) : context(map) { }
    int getHopLimit() const;
    int getId() const;
    int getNumContextItems() const;
    simtime_t getTimestamp() const;
    int getWireSize () const;
    void setHopLimit(int hopLimit);
    void decrementHopLimit();
    void setId(int id);
    void setTimestamp(simtime_t timestamp);

    void setContextItem(int label, int value);
    ContextMap getContextMap();

    const ContextMap debugGetContextSummary() const { return context; }
};

typedef std::map<int, ContextSummary> ContextSummaryMap;
typedef ContextSummaryMap::const_iterator ContextSummaryMapIterator;

#endif /* CONTEXTSUMMARY_H_ */
