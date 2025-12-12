#include "mbed.h"
#include <cstring>

DigitalOut buzzer(PC_8);
UnbufferedSerial pc(USBTX, USBRX, 115200);

char buffer[32];
int pos = 0;

void send(const char *msg) {
    pc.write(msg, strlen(msg));
}

int main() {
    pc.set_blocking(false);   // 🔴 CRITICAL FIX

    send("\r\n=== BUZZER CONTROL READY ===\r\n");
    send("Commands: on, off, status, help\r\n> ");

    while (true) {
        char c;

        // Non-blocking read
        if (pc.read(&c, 1) > 0) {

            // Echo back so you SEE what you type
            pc.write(&c, 1);

            // ENTER pressed
            if (c == '\r' || c == '\n') {
                buffer[pos] = '\0';
                send("\r\n");

                if (strcmp(buffer, "on") == 0) {
                    buzzer = 1;
                    send("Buzzer: ON\r\n");

                } else if (strcmp(buffer, "off") == 0) {
                    buzzer = 0;
                    send("Buzzer: OFF\r\n");

                } else if (strcmp(buffer, "status") == 0) {
                    send(buzzer.read() ? "Buzzer is ON\r\n" : "Buzzer is OFF\r\n");

                } else if (strcmp(buffer, "help") == 0) {
                    send("Commands:\r\n");
                    send("  on\r\n  off\r\n  status\r\n  help\r\n");

                } else if (pos > 0) {
                    send("Unknown command\r\n");
                }

                pos = 0;
                send("> ");
            }
            else {
                if (pos < sizeof(buffer) - 1 && c >= 32) {
                    buffer[pos++] = c;
                }
            }
        }

        ThisThread::sleep_for(5ms);
    }
}
