#include "w65c22.h"

unsigned char led = 0;

void main(void) {
    portMode(0, OUTPUT);
    portMode(1, OUTPUT);
    portMode(2, OUTPUT);
    portMode(3, OUTPUT);
    portMode(4, OUTPUT);

    while (1) {
        writePort(led, HIGH);
        writePort(led, LOW);

        led++;
        if (led > 7) {
            led = 0;
        }
    }
}