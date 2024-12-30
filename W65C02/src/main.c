#include <stdbool.h>
#include <limits.h>
#include "w65c22.h"

unsigned int i = 0;
bool ascending = true;
unsigned short led = 0;

void main(void) {
    portMode(0, OUTPUT);
    portMode(1, OUTPUT);
    portMode(2, OUTPUT);
    portMode(3, OUTPUT);
    portMode(4, OUTPUT);

    while (1) {
        writePort(led, HIGH);
        for (i = 0; i < USHRT_MAX / 2; i++) {
        __asm__ ("nop");
        }
        writePort(led, LOW);

        if (ascending == true) {
            led++;
            if (led >= 4) {
                ascending = false;
            }
        }
        else {
            led--;
            if (led == 0) {
                ascending = true;
            }
        }
    }
}