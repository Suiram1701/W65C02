#include "w65c22.h"
#include "hd44780.h"

void main(void) {
    portModes(0xFFFF);

    lcdFunctionSet(LCD_TWO_LINES | LCD_SMALL_FONT);
    lcdDisplayControl(LCD_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF);
    lcdEntryModeSet(LCD_INCREMENT | LCD_ACCOMPANIES_SHIFT);

    lcdClearDisplay();
    lcdWriteString("Hello");
    lcdSetCursor(1, 11);
    lcdWriteString("World");
}