  #include "Arduino.h"
  #include "TimeTrigger.h"

  unsigned long   Interval  = 0;
  unsigned long   Previous  = 0;
  unsigned long   Current   = 0;
  bool            State     = LOW;

  TimeTrigger::TimeTrigger(unsigned long Time)
  {
    Interval = Time;
  }

  bool  TimeTrigger::Trigger()
  {
    Current = millis();
    if(Current - Previous >= Interval)
    {
      Previous = Current;
      State = !State;
      return HIGH;
    } else {
      return LOW;
    }
  }

  void TimeTrigger::SetInterval(unsigned long Time)
  {
    Interval = Time;       // Time Set Will Be The interval Time
  }

  void TimeTrigger::Reset()
  {
  	Previous = millis();   // Take The Current Time
  	Current = Previous;    // Make Previous & Current The Same
  	State = LOW;           // Make The FlipFlop State LOW
  }

  bool TimeTrigger::FlipFlop()
  {
    Trigger();            // Executes The Trigger Function
    return State;         // Returns The State Value
  }
