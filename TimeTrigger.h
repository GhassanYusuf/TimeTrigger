#ifndef TimeTrigger_h
#define TimeTrigger_h

#include "Arduino.h"

class TimeTrigger
{
  public:
    TimeTrigger(unsigned long Time); // This is a Constructor With Time Interval Setup
    void SetInterval(unsigned long Time); // This Sets The Time Interval Of Each Occurance
    bool FlipFlop();  // This Toggles The Output (True/False)
    bool Trigger();   // This Is The Event Occure Flag Goes High When Time Is Up
    void Reset();     // This Resets The Timing
  private:
    unsigned long   Interval  = 0;
    unsigned long   Previous  = 0;
    unsigned long   Current   = 0;
    bool            State     = LOW;
};

#endif
