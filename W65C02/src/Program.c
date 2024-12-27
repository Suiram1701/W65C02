#include "w65c22.h"

void main(void) {
    setDDR(DDRA, 2, OUTPUT);
    setPort(PORTA, 2, HIGH);

    while (1);
}