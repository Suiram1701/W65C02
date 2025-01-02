#ifndef HD44780U_H
#define HD44780U_H

#include <stdint.h>

#define LCD_INCREMENT         0b00000010
#define LCD_INCREMENT         0
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

/// @brief Clears the entire LCD display.
void lcdClearDisplay(void);

/// @brief Returns the cursor to the start position.
void lcdReturnHome(void);

/// @brief Sets the entry mode for the LCD.
/// @param entryModeFlags The flags to apply. Available flags: LCD_INCREMENT, LCD_INCREMENT and LCD_ACCOMPANIES_SHIFT are available
void lcdEntryModeSet(uint8_t entryModeFlags);

/// @brief Controls which components of the LCD display are enabled. Components are the entire display, the cursor and the blicking of the cursor.
/// @param controlFlags The enabled flags to apply.
void lcdDisplayControl(uint8_t controlFlags);

/// @brief Sets how the LCD should shift its content.
/// @param shiftFlags The shift flags to apply. Available flags: LCD_DISPLAY_SHIFT, LCD_CURSOR_MOVE, LCD_SHIFT_RIGHT and LCD_SHIFT_LEFT.
void lcdDisplayShift(uint8_t shiftFlags);

/// @brief Initializes the display with certain hardware specification.
/// @param functionFlags The function flags to apply. Available 
void lcdFunctionSet(uint8_t functionFlags);

/// @brief Sets the dispalyed cursor and write address to a certain row and coloumn. 
/// @param row The row to set. Zero based.
/// @param column The column to set. Zero based.
void lcdSetCursor(uint8_t row, uint8_t column);

/// @brief Writes a single char to the LCD.
/// @param value The char to write.
void lcdWriteChar(uint8_t value);

/// @brief Writes a complete string to the LCD.
/// @param value The string to write to.
void lcdWriteString(uint8_t* value);

#endif