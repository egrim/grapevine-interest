cplusplus {{
    #include <map>
    #include "ContextSummary.h"
    typedef std::map<int, ContextSummary> ContextSummaryMap;
}}

class noncobject ContextSummaryMap;

packet GrapevinePacket {
    @customize(true);
    int payloadSize;
    ContextSummaryMap summaries;
};
