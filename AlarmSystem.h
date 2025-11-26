#ifndef ALARM_SYSTEM_H
#define ALARM_SYSTEM_H

#include "mbed.h"

class AlarmSystem
{
public:
    AlarmSystem(PinName ledPin, UnbufferedSerial &serial);

    void activate();
    void deactivate();
    bool isActive() const;
    void blink();

private:
    DigitalOut led_;
    bool active_;
    UnbufferedSerial &pc_;
};

#endif