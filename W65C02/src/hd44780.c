#include <stdint.h>
#include <limits.h>
#include <6502.h>
#include "hd44780.h"
#include "w65c22.h"

static uint16_t __lcdWait;     // If 8 bit would be used instead of 16 bit the time spent with the delay is not enough time for the LCD.
static uint8_t __lcdChar;
static uint8_t __lcdPort;

static const uint8_t __lcdRowOffset[] = { 0x0, 0x40, 0x0 + 16, 0x40 + 16 };

void __sendLcdData(HD44780* device, uint8_t data) {
    SEI();

    writePort(device->rw, LOW);
    writePort(device->e, LOW);

    for (__lcdPort = 0; __lcdPort <= 7; __lcdPort++) {
        writePort(device->data[__lcdPort], (data >> __lcdPort) & 1);
    }

    writePort(device->e, HIGH);
    writePort(device->e, LOW);

    CLI();
}

void lcdClearDisplay(HD44780* device) {
    writePort(device->rs, LOW);
    __sendLcdData(device, 1);
}

void lcdReturnHome(HD44780* device) {
    writePort(device->rs, LOW);
    __sendLcdData(device, 2);
}

void lcdEntryModeSet(HD44780* device, uint8_t entryModeFlags) {
    writePort(device->rs, LOW);
    __sendLcdData(device, 0x4 | entryModeFlags);     // 0x4 = 0b00000100
}

void lcdDisplayControl(HD44780* device, uint8_t controlFlags) {
    writePort(device->rs, LOW);
    __sendLcdData(device, 0x8 | controlFlags);     // 0x8 = 0b00001000
}

void lcdDisplayShift(HD44780* device, uint8_t shiftFlags) {
    writePort(device->rs, LOW);
    __sendLcdData(device, 0x10 | shiftFlags);     // 0x10 = 0b00010000
}

void lcdFunctionSet(HD44780* device, uint8_t functionFlags) {
    // A delay is required to give the LCD some time to initialize internally (see __lcdWait declaration for more specific)
    for (__lcdWait = 0; __lcdWait < UINT8_MAX; __lcdWait++) {
        __asm__ ("nop");
    }

    writePort(device->rs, LOW);
    __sendLcdData(device, 0x20 | 0x10 | functionFlags);     // 0x20 = 0b00100000; 0x10 = 0b00010000 (Constant for current 8bit only support)
}

void lcdSetCursor(HD44780* device, uint8_t row, uint8_t column) {
    if (row > 3) return;     // row out of range

    writePort(device->rs, LOW);
    __sendLcdData(device, 0x80 | (__lcdRowOffset[row] + column));     // 0x80 = 0b01000000
}

void lcdWriteChar(HD44780* device, char character) {
    writePort(device->rs, HIGH);
    __sendLcdData(device, character);
}

void lcdWriteString(HD44780* device, char* value) {
    for (__lcdChar = 0; value[__lcdChar] != '\0'; __lcdChar++) {
        lcdWriteChar(device, value[__lcdChar]);
    }
}