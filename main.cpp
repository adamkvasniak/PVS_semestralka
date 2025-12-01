#include "mbed.h"
#include "AlarmSystem.h"
#include "MotionSensor.h"

UnbufferedSerial pc(USBTX, USBRX, 115200);

// Adjust to your board pins:
#define MOTION_PIN  A0      // Analog PIR / motion sensor read
#define LED_PIN     LED1    // Alarm LED
#define BUZZER_PIN  D3      // Active buzzer (DigitalOut)

DigitalOut buzzer(BUZZER_PIN);

int main() 
{
    pc.write("System starting...\r\n", 20);

    MotionSensor motion(MOTION_PIN, 0.25f); // threshold 0.25
    AlarmSystem alarm(LED_PIN, pc);

    while (true)
    {
        bool detected = motion.detect_motion();

        if (detected)
        {
            alarm.activate();
            buzzer = 1;
        }
        else
        {
            alarm.deactivate();
            buzzer = 0;
        }

        if (alarm.isActive())
        {
            alarm.blink(); // LED blink when active
        }

        ThisThread::sleep_for(200ms);
    }
}
