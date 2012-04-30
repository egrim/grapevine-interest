cplusplus {{
    #include <map>
    #include "InterestSummary.h"
    #include "ContextSummary.h"
}}

class InterestSummary extends cObject;
class noncobject ContextSummaryMap;

packet GrapevinePacket {
    @customize(true);
    int payloadSize;

    bool trackInterest = false;
    InterestSummary interest;

    ContextSummaryMap summaries;
};
