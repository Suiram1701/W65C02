#include "w65c22.h"

#define __W65C22_BASE  0x6000
#define __W65C22_PORTB (__W65C22_BASE + 0x00)
#define __W65C22_PORTA (__W65C22_BASE + 0x01)
#define __W65C22_DDRB  (__W65C22_BASE + 0x02)
#define __W65C22_DDRA  (__W65C22_BASE + 0x03)

#define __Address(addr) (*(unsigned char*)addr)

void __fastcall__ _modifyBit(unsigned short addr, unsigned char bit, unsigned char value) {
    if (bit > 7) return;

    if (value > 0) {
        __Address(addr) |= (1 << bit);
    }
    else {
        __Address(addr) &= ~(1 << bit);
    }
}

signed char __fastcall__ _readBit(unsigned short addr, unsigned char bit) {
    if (bit > 7) return -1;     // Port out of range

    return (__Address(addr) >> bit) & 1;
}

void __fastcall__ portMode(unsigned char port, unsigned char mode) {
    if (port > 15) return;     // Port out of range
    
    if (port <= 7) {
        _modifyBit(__W65C22_DDRA, port, mode);
    }
    else {
        _modifyBit(__W65C22_DDRB, port - 8, mode);
    }
}

void __fastcall__ portModes(unsigned short ports) {
    __Address(__W65C22_DDRA) = (unsigned char)(ports & 255);
    __Address(__W65C22_DDRB) = (unsigned char)(ports >> 8);
}

void __fastcall__ writePort(unsigned short port, unsigned char value) {
    if (port > 15) return;     // Port out of range
    
    if (port <= 7) {
        _modifyBit(__W65C22_PORTA, port, value);
    }
    else {
        _modifyBit(__W65C22_PORTB, port - 8, value);
    }
}

void __fastcall__ writePorts(unsigned short ports) {
    __Address(__W65C22_PORTA) = (unsigned char)(ports & 255);
    __Address(__W65C22_PORTB) = (unsigned char)(ports >> 8);
}

signed char __fastcall__ readPort(unsigned short port) {
    if (port > 15) return -1;

    if (port <= 7) {
        return _readBit(__W65C22_PORTA, port);
    }
    else {
        return _readBit(__W65C22_PORTB, port - 8);
    }
}

unsigned short __fastcall__ readPorts(void) {
    return (__Address(__W65C22_PORTB) << 8) + __Address(__W65C22_PORTA); 
}