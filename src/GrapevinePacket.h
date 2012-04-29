#ifndef GRAPEVINEPACKET_H_
#define GRAPEVINEPACKET_H_

#include "GrapevinePacket_m.h"
class GrapevinePacket: public GrapevinePacket_Base {
private:
    void copy(const GrapevinePacket& other);

public:
    GrapevinePacket(const char *name = NULL, int kind = 0) :
            GrapevinePacket_Base(name, kind) {
    }
    GrapevinePacket(const GrapevinePacket& other) :
            GrapevinePacket_Base(other) {
        copy(other);
    }
    GrapevinePacket& operator=(const GrapevinePacket& other) {
        if (this == &other)
            return *this;
        GrapevinePacket_Base::operator=(other);
        copy(other);
        return *this;
    }
    virtual GrapevinePacket *dup() const {
        return new GrapevinePacket(*this);
    }

    virtual void addContextSummary(ContextSummary summary);

    virtual void updatePacketLength();
};
#endif /* GRAPEVINEPACKET_H_ */
