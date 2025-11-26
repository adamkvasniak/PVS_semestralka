#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include "mbed.h"

class MotionSensor
{
public:
    MotionSensor(PinName pin, float threshold = 0.3f);
    bool detect_motion();
    float get_last_value() const;

private:
    AnalogIn sensor_;
    float threshold_;
    float lastValue_;
};

#endif