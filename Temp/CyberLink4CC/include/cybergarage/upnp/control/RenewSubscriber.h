/******************************************************************
*
*  CyberLink for C++
*
*  Copyright (C) Satoshi Konno 2002-2003
*
*  File: RenewSubscriber.h
*
*  Revision;
*
*  07/07/04
*    - first revision
*
******************************************************************/

#ifndef _CLINK_RENEWSUBSCRIBER_H_
#define _CLINK_RENEWSUBSCRIBER_H_

#include <uhttp/util/Thread.h>
#include <uhttp/util/TimeUtil.h>

namespace CyberLink {
class ControlPoint;

class RenewSubscriber : public uHTTP::Thread {
 public:
  ////////////////////////////////////////////////
  //  Constants
  ////////////////////////////////////////////////

  static const long INTERVAL;

  ////////////////////////////////////////////////
  //  Constructor
  ////////////////////////////////////////////////

 public:
  RenewSubscriber(ControlPoint *ctrlp) {
    setControlPoint(ctrlp);
  }
  
  ////////////////////////////////////////////////
  //  Member
  ////////////////////////////////////////////////

private:
  
  ControlPoint *controlPoint;
  uHTTP::CTimeUtil m_timeUtil;
 public:
  void setControlPoint(ControlPoint *ctrlp) {
    controlPoint = ctrlp;
  }
  
  ControlPoint *getControlPoint() {
    return controlPoint;
  }

  ////////////////////////////////////////////////
  //  Thread
  ////////////////////////////////////////////////
  
 public:
   virtual void run();
   virtual bool stop();
};

}

#endif

