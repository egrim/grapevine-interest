cplusplus {{
    #include <map>
    #include "ContextSummary.h"
}}

class noncobject ContextSummaryMap;

packet GrapevinePacket {
    @customize(true);
    int payloadSize;
    ContextSummaryMap summaries;
};
