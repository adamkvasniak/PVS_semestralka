#include "mbed.h"

DigitalOut buzzer(PC_8);
DigitalIn button(PC_13); // B1

int main() {
    button.mode(PullNone);   // IMPORTANT! B1 has HW pull-down on board

    while (1) {
        if (button.read() == 1) {   // Pressed
            buzzer = 1;
        } else {
            buzzer = 0;
        }

        ThisThread::sleep_for(10ms);
    }
}
