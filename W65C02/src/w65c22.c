#include "w65c22.h"

#define _Address(addr) (*(unsigned char*)addr)

void __fastcall__ setDDRs(unsigned short addr, unsigned char ports) {
    _Address(addr) = ports;
}

void __fastcall__ setDDR(unsigned short addr, unsigned char port, unsigned char output) {
    if (port >= 8) return;     // Port out of range

    if (output > 0) {
        _Address(addr) |= (1 << port);
    }
    else {
        _Address(addr) &= ~(1 << port);
    }
}

void __fastcall__ setPorts(unsigned short addr, unsigned char values) {
    _Address(addr) = values;
}

void __fastcall__ setPort(unsigned short addr, unsigned char port, unsigned char value) {
    if (port >= 8) return;     // Port out of range

    if (value > 0) {
        _Address(addr) |= (1 << port);
    }
    else {
        _Address(addr) &= ~(1 << port);
    }
}

unsigned char __fastcall__ getPorts(unsigned short addr) {
    return _Address(addr);
}

unsigned char __fastcall__ getPort(unsigned short addr, unsigned char port) {
    if (port >= 8) return -1;     // Port out of range

    return (_Address(addr) >> port) & 1;
}