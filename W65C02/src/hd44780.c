#include <stdint.h>
#include <6502.h>
#include <limits.h>
#include "hd44780.h"
#include "w65c22.h"

#define __HD44780U      5
#define __HD44780U_RS   (__HD44780U + 0)
#define __HD44780U_RW   (__HD44780U + 1)
#define __HD44780U_E    (__HD44780U + 2)
#define __HD44780U_Data (__HD44780U + 3)
#define __HD44780U_Busy (__HD44780U + 10)

static uint8_t __lcdInitT;
static uint8_t __lcdDataPort;
static uint8_t __lcdCurrentChar;

static const uint8_t __lcdRowOffset[] = {
    0x0,
    0x40,
    0x0 + 16,
    0x40 + 16
};

void __sendLcdData(uint8_t data) {
    SEI();

    writePort(__HD44780U_RW, LOW);
    writePort(__HD44780U_E, LOW);

    for (__lcdDataPort = 0; __lcdDataPort <= 7; __lcdDataPort++) {
        writePort(__lcdDataPort + __HD44780U_Data, (data >> __lcdDataPort) & 1);
    }

    writePort(__HD44780U_E, HIGH);
    writePort(__HD44780U_E, LOW);

    CLI();
}

void lcdClearDisplay(void) {
    writePort(__HD44780U_RS, LOW);
    __sendLcdData(1);
}

void lcdReturnHome(void) {
    writePort(__HD44780U_RS, LOW);
    __sendLcdData(2);
}

void lcdEntryModeSet(uint8_t entryModeFlags) {
    writePort(__HD44780U_RS, LOW);
    __sendLcdData(0x4 | entryModeFlags);     // 0x4 = 0b00000100
}

void lcdDisplayControl(uint8_t controlFlags) {
    writePort(__HD44780U_RS, LOW);
    __sendLcdData(0x8 | controlFlags);     // 0x8 = 0b00001000
}

void lcdDisplayShift(uint8_t shiftFlags) {
    writePort(__HD44780U_RS, LOW);
    __sendLcdData(0x10 | shiftFlags);     // 0x10 = 0b00010000
}

void lcdFunctionSet(uint8_t functionFlags) {
    // A delay is required to give the LCD some time to initialize internally
    for (__lcdInitT = 0; __lcdInitT < UINT8_MAX; __lcdInitT++) {
        __asm__ ("nop");
    }

    writePort(__HD44780U_RS, LOW);
    __sendLcdData(0x20 | 0x10 | functionFlags);     // 0x20 = 0b00100000; 0x10 = 0b00010000 (Constant for current 8bit only support)
}

void lcdSetCursor(uint8_t row, uint8_t column) {
    if (row > 3) return;     // row out of range

    writePort(__HD44780U_RS, LOW);
    __sendLcdData(0x80 | (__lcdRowOffset[row] + column));     // 0x80 = 0b01000000; The row offset is actually 0 = 0x0; 1 = 0x40; 2 = max_columns; 3 = 0x40 + max_columns but more that 2 lines are currently not supported
}

void lcdWriteChar(uint8_t character) {
    writePort(__HD44780U_RS, HIGH);
    __sendLcdData(character);
}

void lcdWriteString(uint8_t* value) {
    for (__lcdCurrentChar = 0; value[__lcdCurrentChar] != '\0'; __lcdCurrentChar++) {
        lcdWriteChar(value[__lcdCurrentChar]);
    }
}