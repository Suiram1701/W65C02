#include <stdint.h>
#include "w65c22.h"

#define __SetBit(value, bit)   ((value) |= (1 << (bit)))
#define __ClearBit(value, bit) ((value) &= ~(1 << (bit)))
#define __ReadBit(value, bit)  (((value) >> (bit)) & 1)

typedef struct W65C22 {
    uint8_t portB;
    uint8_t portA;
    uint8_t ddrB;
    uint8_t ddrA;
} W65C22;

#define VIA ((volatile W65C22*)0x6000)

void portMode(uint8_t port, uint8_t mode) {
    if (port > 15) return;     // Port out of range

    if (port <= 7) {
        mode == OUTPUT
            ? __SetBit(VIA->ddrA, port)
            : __ClearBit(VIA->ddrA, port);
    }
    else {
        mode == OUTPUT
            ? __SetBit(VIA->ddrB, port - 8)
            : __ClearBit(VIA->ddrB, port - 8);
    }
}

void portModes(uint16_t ports) {
    VIA->ddrA = ports & 255;
    VIA->ddrB = ports >> 8;
}

void writePort(uint8_t port, uint8_t value) {
    if (port > 15) return;     // Port out of range
    
    if (port <= 7) {
        value == HIGH
            ? __SetBit(VIA->portA, port)
            : __ClearBit(VIA->portA, port);
    }
    else {
        value == HIGH
            ? __SetBit(VIA->portB, port - 8)
            : __ClearBit(VIA->portB, port - 8);
    }
}

void writePorts(uint16_t ports) {
    VIA->portA = ports & 255;
    VIA->portB = ports >> 8;
}

int8_t readPort(uint8_t port) {
    if (port > 15) return -1;

    if (port <= 7) {
        return __ReadBit(VIA->portA, port);
    }
    else {
        return __ReadBit(VIA->portB, port - 8);
    }
}

uint16_t readPorts(void) {
    return (VIA->portB << 8) | VIA->portA;
}