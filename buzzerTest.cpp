#include "mbed.h"

DigitalOut buzzer(PC_8); 
DigitalIn button(PC_13); // B1

int main() {
    button.mode(PullUp);  // B1: pressed = 0

    while (1) {
        if (button.read() == 0) {  // Stlačené
            buzzer = 1;
        } else {
            buzzer = 0;
        }

        ThisThread::sleep_for(10ms);
    }
}
