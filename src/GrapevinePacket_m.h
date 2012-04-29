//
// Generated file, do not edit! Created by opp_msgc 4.2 from GrapevinePacket.msg.
//

#ifndef _GRAPEVINEPACKET_M_H_
#define _GRAPEVINEPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <map>
    #include "ContextSummary.h"
    typedef std::map<int, ContextSummary> ContextSummaryMap;
// }}



/**
 * Class generated from <tt>GrapevinePacket.msg</tt> by opp_msgc.
 * <pre>
 * packet GrapevinePacket {
 *     @customize(true);
 *     int payloadSize;
 *     ContextSummaryMap summaries;
 * };
 * </pre>
 *
 * GrapevinePacket_Base is only useful if it gets subclassed, and GrapevinePacket is derived from it.
 * The minimum code to be written for GrapevinePacket is the following:
 *
 * <pre>
 * class GrapevinePacket : public GrapevinePacket_Base
 * {
 *   private:
 *     void copy(const GrapevinePacket& other) { ... }

 *   public:
 *     GrapevinePacket(const char *name=NULL, int kind=0) : GrapevinePacket_Base(name,kind) {}
 *     GrapevinePacket(const GrapevinePacket& other) : GrapevinePacket_Base(other) {copy(other);}
 *     GrapevinePacket& operator=(const GrapevinePacket& other) {if (this==&other) return *this; GrapevinePacket_Base::operator=(other); copy(other); return *this;}
 *     virtual GrapevinePacket *dup() const {return new GrapevinePacket(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from GrapevinePacket_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(GrapevinePacket);
 * </pre>
 */
class GrapevinePacket_Base : public ::cPacket
{
  protected:
    int payloadSize_var;
    ContextSummaryMap summaries_var;

  private:
    void copy(const GrapevinePacket_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const GrapevinePacket_Base&);
    // make constructors protected to avoid instantiation
    GrapevinePacket_Base(const char *name=NULL, int kind=0);
    GrapevinePacket_Base(const GrapevinePacket_Base& other);
    // make assignment operator protected to force the user override it
    GrapevinePacket_Base& operator=(const GrapevinePacket_Base& other);

  public:
    virtual ~GrapevinePacket_Base();
    virtual GrapevinePacket_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class GrapevinePacket");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getPayloadSize() const;
    virtual void setPayloadSize(int payloadSize);
    virtual ContextSummaryMap& getSummaries();
    virtual const ContextSummaryMap& getSummaries() const {return const_cast<GrapevinePacket_Base*>(this)->getSummaries();}
    virtual void setSummaries(const ContextSummaryMap& summaries);
};


#endif // _GRAPEVINEPACKET_M_H_