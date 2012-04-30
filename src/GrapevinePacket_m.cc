//
// Generated file, do not edit! Created by opp_msgc 4.2 from GrapevinePacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "GrapevinePacket_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




GrapevinePacket_Base::GrapevinePacket_Base(const char *name, int kind) : cPacket(name,kind)
{
    this->payloadSize_var = 0;
    this->trackInterest_var = false;
}

GrapevinePacket_Base::GrapevinePacket_Base(const GrapevinePacket_Base& other) : cPacket(other)
{
    copy(other);
}

GrapevinePacket_Base::~GrapevinePacket_Base()
{
}

GrapevinePacket_Base& GrapevinePacket_Base::operator=(const GrapevinePacket_Base& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void GrapevinePacket_Base::copy(const GrapevinePacket_Base& other)
{
    this->payloadSize_var = other.payloadSize_var;
    this->trackInterest_var = other.trackInterest_var;
    this->interest_var = other.interest_var;
    this->summaries_var = other.summaries_var;
}

void GrapevinePacket_Base::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->payloadSize_var);
    doPacking(b,this->trackInterest_var);
    doPacking(b,this->interest_var);
    doPacking(b,this->summaries_var);
}

void GrapevinePacket_Base::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->payloadSize_var);
    doUnpacking(b,this->trackInterest_var);
    doUnpacking(b,this->interest_var);
    doUnpacking(b,this->summaries_var);
}

int GrapevinePacket_Base::getPayloadSize() const
{
    return payloadSize_var;
}

void GrapevinePacket_Base::setPayloadSize(int payloadSize)
{
    this->payloadSize_var = payloadSize;
}

bool GrapevinePacket_Base::getTrackInterest() const
{
    return trackInterest_var;
}

void GrapevinePacket_Base::setTrackInterest(bool trackInterest)
{
    this->trackInterest_var = trackInterest;
}

InterestSummary& GrapevinePacket_Base::getInterest()
{
    return interest_var;
}

void GrapevinePacket_Base::setInterest(const InterestSummary& interest)
{
    this->interest_var = interest;
}

ContextSummaryMap& GrapevinePacket_Base::getSummaries()
{
    return summaries_var;
}

void GrapevinePacket_Base::setSummaries(const ContextSummaryMap& summaries)
{
    this->summaries_var = summaries;
}

class GrapevinePacketDescriptor : public cClassDescriptor
{
  public:
    GrapevinePacketDescriptor();
    virtual ~GrapevinePacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(GrapevinePacketDescriptor);

GrapevinePacketDescriptor::GrapevinePacketDescriptor() : cClassDescriptor("GrapevinePacket", "cPacket")
{
}

GrapevinePacketDescriptor::~GrapevinePacketDescriptor()
{
}

bool GrapevinePacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<GrapevinePacket_Base *>(obj)!=NULL;
}

const char *GrapevinePacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int GrapevinePacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int GrapevinePacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *GrapevinePacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "payloadSize",
        "trackInterest",
        "interest",
        "summaries",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int GrapevinePacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadSize")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "trackInterest")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "interest")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "summaries")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *GrapevinePacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "InterestSummary",
        "ContextSummaryMap",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *GrapevinePacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int GrapevinePacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    GrapevinePacket_Base *pp = (GrapevinePacket_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string GrapevinePacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    GrapevinePacket_Base *pp = (GrapevinePacket_Base *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadSize());
        case 1: return bool2string(pp->getTrackInterest());
        case 2: {std::stringstream out; out << pp->getInterest(); return out.str();}
        case 3: {std::stringstream out; out << pp->getSummaries(); return out.str();}
        default: return "";
    }
}

bool GrapevinePacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    GrapevinePacket_Base *pp = (GrapevinePacket_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadSize(string2long(value)); return true;
        case 1: pp->setTrackInterest(string2bool(value)); return true;
        default: return false;
    }
}

const char *GrapevinePacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        "InterestSummary",
        "ContextSummaryMap",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *GrapevinePacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    GrapevinePacket_Base *pp = (GrapevinePacket_Base *)object; (void)pp;
    switch (field) {
        case 2: return (void *)static_cast<cObject *>(&pp->getInterest()); break;
        case 3: return (void *)(&pp->getSummaries()); break;
        default: return NULL;
    }
}


