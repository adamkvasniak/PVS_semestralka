#include "mbed.h"

PwmOut buzzer(PC_8);   // PWM výstup na pin PC_8

int main() {
    // Nastaví frekvenciu 2 kHz (PIR buzzery najčastejšie fungujú 1–5 kHz)
    buzzer.period(1.0f / 2000.0f);  // 2000 Hz

    // 50% výkon (hlasitosť)
    buzzer.write(0.5f);  

    while (1) {
        // Buzzer stále hrá
        ThisThread::sleep_for(1s);
    }
}
