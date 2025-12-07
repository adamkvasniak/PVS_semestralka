#include "mbed.h"

DigitalOut buzzer(PC_8);        // Aktívny buzzer
DigitalIn pir(D4);              // PIR OUT → D4
UnbufferedSerial pc(USBTX, USBRX, 115200);

int main() {
    pir.mode(PullDown);

    bool lastState = false;     // sledujeme zmenu stavu PIR

    pc.write("System started.\r\n", 18);

    while (1) {

        bool motion = pir.read();

        if (motion && !lastState) {
            // PIR práve DETEGOVAL pohyb
            pc.write("MOTION DETECTED - BUZZER ON\r\n", 30);
        }

        if (!motion && lastState) {
            // PIR práve stratil pohyb
            pc.write("NO MOTION - BUZZER OFF\r\n", 25);
        }

        buzzer = motion ? 1 : 0;   // zapni/vypni buzzer podľa PIR
        lastState = motion;

        ThisThread::sleep_for(50ms);
    }
}
