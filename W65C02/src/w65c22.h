#ifndef W65C22_H
#define W65C22_H

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

/// @brief Sets the mode (input/output) of a single port.
/// @param port A port from zero to 15 where 0 to seven are A's ports and eight to 15 B's ports.
/// @param mode The mode to set on this port
void __fastcall__ portMode(unsigned char port, unsigned char mode);

/// @brief Sets the mode (input/output) of all ports on the chip.
/// @param ports The mode of all 16 ports. The first bit is port zero and the last one port 15. Zero represents input and one output.
void __fastcall__ portModes(unsigned short ports);

/// @brief Sets the output value of a certain port.
/// @param port A port from zero to 15 where 0 to seven are A's ports and eight to 15 B's ports.
/// @param value The logical value to set.
void __fastcall__ writePort(unsigned short port, unsigned char value);

/// @brief Sets the output values of all ports.
/// @param ports The logical output value of all 16 ports. The first bit is port zero and the last one port 15.
void __fastcall__ writePorts(unsigned short ports);

/// @brief Gets the current input/output value of a single port.
/// @param port A port from zero to 15 where 0 to seven are A's ports and eight to 15 B's ports.
/// @return Zero means the port is unpowered and everything upward means it's powered. Minus one means the specified port is out of range.
signed char __fastcall__ readPort(unsigned short port);

/// @brief Gets the current input/output values of all ports.
/// @param addr The address of the ports register (use constants).
/// @return The first bit is corresponding to port zero, the second bit to port one and so on. One means powered and zero unpowered.
unsigned short __fastcall__ readPorts(void);

#endif