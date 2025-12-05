#include "mbed.h"

PwmOut buzzer(PC_8);     // PWM výstup na buzzer
DigitalIn button(PC_13); // USER BUTTON B1

int main() {
    button.mode(PullUp);        // B1 je aktívny v log. 0
    buzzer.period(1.0f / 2000); // 2 kHz tón

    while (1) {
        if (button.read() == 0) {   // Stlačené
            buzzer.write(0.5f);     // 50% hlasitosť
        } else {
            buzzer.write(0.0f);     // Off
        }

        ThisThread::sleep_for(10ms);
    }
}
