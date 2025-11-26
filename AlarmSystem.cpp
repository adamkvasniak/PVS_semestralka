#include "AlarmSystem.h"
#include <cstring> // strlen

AlarmSystem::AlarmSystem(PinName ledPin, UnbufferedSerial &serial)
    : led_(ledPin), active_(false), pc_(serial) {}

void AlarmSystem::activate()
{
    if (!active_)
    {
        active_ = true;
        const char *msg = "ALARM AKTIVOVANY!\r\n";
        pc_.write(msg, strlen(msg));
    }
}

void AlarmSystem::deactivate()
{
    if (active_)
    {
        active_ = false;
        led_ = 0;
        const char *msg = "Alarm deaktivovany.\r\n";
        pc_.write(msg, strlen(msg));
    }
}

bool AlarmSystem::isActive() const
{
    return active_;
}

void AlarmSystem::blink()
{
    if (active_)
    {
        led_ = !led_;
    }
}