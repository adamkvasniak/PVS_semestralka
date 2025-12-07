#include "mbed.h"

DigitalOut buzzer(PC_8);        // Aktívny buzzer
DigitalIn pir(D4);              // PIR OUT → D4
UnbufferedSerial pc(USBTX, USBRX, 115200);

int main() {
    pir.mode(PullDown);

    bool lastState = false;

    pc.write("System started.\r\n", 18);

    while (1) {
        bool motion = pir.read();

        if (motion && !lastState) {
            // PIR práve detegoval pohyb (nábežná hrana)
            pc.write("MOTION DETECTED\r\n", 19);

            // KRÁTKE PÍPNUTIE – 200 ms
            buzzer = 1;
            ThisThread::sleep_for(200ms);
            buzzer = 0;
        }

        if (!motion && lastState) {
            pc.write("NO MOTION\r\n", 11);
        }

        lastState = motion;
        ThisThread::sleep_for(20ms);
    }
}
