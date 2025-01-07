#ifndef W65C22_H
#define W65C22_H

#include <stdint.h>

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

/// @brief Sets the mode (input/output) of a single port.
/// @param port A port from zero to 15 where 0 to seven are A's ports and eight to 15 B's ports.
/// @param mode The mode to set on this port
void portMode(uint8_t port, uint8_t mode);

/// @brief Sets the mode (input/output) of all ports on the chip.
/// @param ports The mode of all 16 ports. The first bit is port zero and the last one port 15. Zero represents input and one output.
void portModes(uint16_t ports);

/// @brief Sets the output value of a certain port.
/// @param port A port from zero to 15 where 0 to seven are A's ports and eight to 15 B's ports.
/// @param value The logical value to set.
void writePort(uint8_t port, uint8_t value);

/// @brief Sets the output values of all ports.
/// @param ports The logical output value of all 16 ports. The first bit is port zero and the last one port 15.
void writePorts(uint16_t ports);

/// @brief Gets the current input/output value of a single port.
/// @param port A port from zero to 15 where 0 to seven are A's ports and eight to 15 B's ports.
/// @return Zero means the port is unpowered and everything upward means it's powered. Minus one means the specified port is out of range.
int8_t readPort(uint8_t port);

/// @brief Gets the current input/output values of all ports.
/// @return The first bit is corresponding to port zero, the second bit to port one and so on. One means powered and zero unpowered.
uint16_t readPorts(void);

#endif