#include "MotionSensor.h"

MotionSensor::MotionSensor(PinName pin, float threshold)
    : sensor_(pin), threshold_(threshold), lastValue_(0.0f) {}

bool MotionSensor::detect_motion()
{
    float value = sensor_.read();
    lastValue_ = value;
    return value > threshold_;
}

float MotionSensor::get_last_value() const
{
    return lastValue_;
}