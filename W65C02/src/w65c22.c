#include <stdint.h>
#include "w65c22.h"

#define __W65C22       0x6000
#define __W65C22_PORTB (__W65C22 + 0x00)
#define __W65C22_PORTA (__W65C22 + 0x01)
#define __W65C22_DDRB  (__W65C22 + 0x02)
#define __W65C22_DDRA  (__W65C22 + 0x03)

#define __Address(addr) (*(uint8_t*)addr)

void _modifyBit(uint16_t addr, uint8_t bit, uint8_t value) {
    if (bit > 7) return;

    if (value > 0) {
        __Address(addr) |= (1 << bit);
    }
    else {
        __Address(addr) &= ~(1 << bit);
    }
}

int8_t _readBit(uint16_t addr, uint8_t bit) {
    if (bit > 7) return -1;     // Port out of range

    return (__Address(addr) >> bit) & 1;
}

void portMode(uint16_t port, uint8_t mode) {
    if (port > 15) return;     // Port out of range
    
    if (port <= 7) {
        _modifyBit(__W65C22_DDRA, port, mode);
    }
    else {
        _modifyBit(__W65C22_DDRB, port - 8, mode);
    }
}

void portModes(uint16_t ports) {
    __Address(__W65C22_DDRA) = (uint8_t)(ports & 255);
    __Address(__W65C22_DDRB) = (uint8_t)(ports >> 8);
}

void writePort(uint16_t port, uint8_t value) {
    if (port > 15) return;     // Port out of range
    
    if (port <= 7) {
        _modifyBit(__W65C22_PORTA, port, value);
    }
    else {
        _modifyBit(__W65C22_PORTB, port - 8, value);
    }
}

void writePorts(uint16_t ports) {
    __Address(__W65C22_PORTA) = (uint8_t)(ports & 255);
    __Address(__W65C22_PORTB) = (uint8_t)(ports >> 8);
}

int8_t readPort(uint16_t port) {
    if (port > 15) return -1;

    if (port <= 7) {
        return _readBit(__W65C22_PORTA, port);
    }
    else {
        return _readBit(__W65C22_PORTB, port - 8);
    }
}

uint16_t readPorts(void) {
    return (__Address(__W65C22_PORTB) << 8) + __Address(__W65C22_PORTA); 
}