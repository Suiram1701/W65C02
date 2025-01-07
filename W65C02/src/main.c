#include "w65c22.h"
#include "hd44780.h"

const static HD44780 LCD = { 5, 6, 7, { 8, 9, 10, 11, 12, 13, 14, 15 } };

void main(void) {
    portModes(0xFFFF);
    writePorts(0b10101);

    lcdFunctionSet(&LCD, LCD_TWO_LINES | LCD_SMALL_FONT);
    lcdDisplayControl(&LCD, LCD_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF);
    lcdEntryModeSet(&LCD, LCD_INCREMENT);

    lcdClearDisplay(&LCD);
    lcdWriteString(&LCD, "Hello, World!");
}