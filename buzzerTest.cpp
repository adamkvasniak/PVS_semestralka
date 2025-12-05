#include "mbed.h"

DigitalOut buzzer(PC_8);

void beep(int on_ms, int off_ms) {
    buzzer = 1;
    ThisThread::sleep_for(std::chrono::milliseconds(on_ms));
    buzzer = 0;
    ThisThread::sleep_for(std::chrono::milliseconds(off_ms));
}

int main() {

    while (1) {

        // --- First phrase ---
        beep(200,100);
        beep(200,100);
        beep(200,100);
        beep(400,200);

        beep(200,100);
        beep(200,100);
        beep(200,100);
        beep(400,200);

        // --- Second phrase ---
        beep(300,100);
        beep(300,100);
        beep(300,100);
        beep(600,200);

        beep(200,100);
        beep(200,100);
        beep(200,100);
        beep(600,300);

        // Small pause between loops
        ThisThread::sleep_for(500ms);
    }
}
