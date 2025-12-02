#include "mbed.h"

DigitalOut buzzer(D3);   // Connect buzzer + wire to D3

int main() {
    buzzer = 1;          // Turn buzzer ON
    while (1) {
        ThisThread::sleep_for(1s);
    }
}
