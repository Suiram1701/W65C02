#ifndef HD44780U_H
#define HD44780U_H

#include <stdint.h>
#include "w65c22.h"

#define LCD_INCREMENT         0b00000010
#define LCD_DECREMENT         0
#define LCD_ACCOMPANIES_SHIFT 0b00000001

#define LCD_ON         0b00000100
#define LCD_OFF        0
#define LCD_CURSOR_ON  0b00000010
#define LCD_CURSOR_OFF 0
#define LCD_BLINK_ON   0b00000001
#define LCD_BLINK_OFF  0

#define LCD_DISPLAY_SHIFT 0b00001000
#define LCD_CURSOR_MOVE   0
#define LCD_SHIFT_RIGHT   0b00000100
#define LCD_SHIFT_LEFT    0

#define LCD_ONE_LINE   0
#define LCD_TWO_LINES  0b00001000
#define LCD_SMALL_FONT 0
#define LCD_LARGE_FONT 0b00000100

typedef struct HD44780 {
    uint8_t rs;
    uint8_t rw;
    uint8_t e;
    uint8_t data[8];
} HD44780;

/// @brief Clears the entire LCD display.
/// @param device The hardware device to access.
void lcdClearDisplay(HD44780* device);

/// @brief Returns the cursor to the start position.
/// @param device The hardware device to access.
void lcdReturnHome(HD44780* device);

/// @brief Sets the entry mode for the LCD.
/// @param device The hardware device to access.
/// @param entryModeFlags The flags to apply. Available flags: LCD_INCREMENT, LCD_INCREMENT and LCD_ACCOMPANIES_SHIFT are available
void lcdEntryModeSet(HD44780* device, uint8_t entryModeFlags);

/// @brief Controls which components of the LCD display are enabled. Components are the entire display, the cursor and the blicking of the cursor.
/// @param device The hardware device to access.
/// @param controlFlags The enabled flags to apply.
void lcdDisplayControl(HD44780* device, uint8_t controlFlags);

/// @brief Sets how the LCD should shift its content.
/// @param device The hardware device to access.
/// @param shiftFlags The shift flags to apply. Available flags: LCD_DISPLAY_SHIFT, LCD_CURSOR_MOVE, LCD_SHIFT_RIGHT and LCD_SHIFT_LEFT.
void lcdDisplayShift(HD44780* device, uint8_t shiftFlags);

/// @brief Initializes the display with certain hardware specification.
/// @param device The hardware device to access.
/// @param functionFlags The function flags to apply. Available 
void lcdFunctionSet(HD44780* device, uint8_t functionFlags);

/// @brief Sets the dispalyed cursor and write address to a certain row and coloumn. 
/// @param device The hardware device to access.
/// @param row The row to set. Zero based.
/// @param column The column to set. Zero based.
void lcdSetCursor(HD44780* device, uint8_t row, uint8_t column);

/// @brief Writes a single char to the LCD.
/// @param device The hardware device to access.
/// @param value The char to write.
void lcdWriteChar(HD44780* device, char value);

/// @brief Writes a complete string to the LCD.
/// @param device The hardware device to access.
/// @param value The string to write to.
void lcdWriteString(HD44780* device, char* value);

#endif