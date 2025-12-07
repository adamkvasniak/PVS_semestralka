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
    send("=== BUZZER CONTROL READY ===\r\n");
    send("Commands: on, off, status, help\r\n");

    while (true) {

        // Ak prisiel znak z konzoly
        char c;
        if (pc.read(&c, 1) == 1) {

            // Enter → spracuj prikaz
            if (c == '\r' || c == '\n') {
                buffer[pos] = '\0';

                if (strcmp(buffer, "on") == 0) {
                    buzzer = 1;
                    send("Buzzer: ON\r\n");

                } else if (strcmp(buffer, "off") == 0) {
                    buzzer = 0;
                    send("Buzzer: OFF\r\n");

                } else if (strcmp(buffer, "status") == 0) {
                    if (buzzer.read())
                        send("Buzzer is ON\r\n");
                    else
                        send("Buzzer is OFF\r\n");

                } else if (strcmp(buffer, "help") == 0) {
                    send("Available commands:\r\n");
                    send("  on     - turn buzzer ON\r\n");
                    send("  off    - turn buzzer OFF\r\n");
                    send("  status - buzzer status\r\n");
                    send("  help   - this help\r\n");

                } else if (pos > 0) {
                    send("Unknown command. Type 'help'\r\n");
                }

                pos = 0; // reset buffer
            } 
            else {
                // Pridaj znak do buffera, pokial je miesto
                if (pos < sizeof(buffer) - 1) {
                    buffer[pos++] = c;
                }
            }
        }
    }
}
