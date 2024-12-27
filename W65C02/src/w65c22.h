#ifndef W65C22_H
#define W65C22_H

#define __W65C22_BASE 0x6000
#define PORTB (__W65C22_BASE + 0x00)
#define PORTA (__W65C22_BASE + 0x01)
#define DDRB (__W65C22_BASE + 0x02)
#define DDRA (__W65C22_BASE + 0x03)

#define OUTPUT 1
#define INPUT 0

#define LOW 0
#define HIGH 1

/// @brief Sets all port directions of a data direction register (DDR).
/// @param addr The address of the DDR to modify (use constants).
/// @param ports The directions to set. The first bit controlls port 0, the second bit controlls port 1 and so on. Is the bit set to 0 will this port and input otherwise an output.
void setDDRs(unsigned short addr, unsigned char ports);

/// @brief Sets the data direction only of a certain port.
/// @param addr The address of the data direction register (DDR) to modify (use constants).
/// @param port The port to modify. Use numbers from zero to seven. If out of range nothing will happen.
/// @param output The new data direction for the port (use constants).
void setDDR(unsigned short addr, unsigned char port, unsigned char output);

/// @brief Sets the output values of all ports.
/// @param addr The address of the ports register (use constants).
/// @param values The ouput values to set. The first bit controlls port 0, the second bit controlls port 1 and so on. One means enabled and zero disabled.
void setPorts(unsigned short addr, unsigned char values);

/// @brief Sets the output value of a certain port.
/// @param addr The address of the ports register (use constants).
/// @param port The port to change the value of. Use numbers from zero to seven. If out of range nothing will happen.
/// @param value The new output value to set (use constants).
void setPort(unsigned short addr, unsigned char port, unsigned char value);

/// @brief Gets the current input values of all ports.
/// @param addr The address of the ports register (use constants).
/// @return The first bit is corresponding  to port 0, the second bit to port 1 and so on. One means powered and zero unpowered.
unsigned char getPorts(unsigned short addr);

/// @brief Gets the current input value of a single port.
/// @param addr The address of the ports register (use constants).
/// @param port The port to get the input value of. Use numbers from zero to seven.
/// @return Zero means the port is unpowered and everything upward means it's powered. Minus one means the specified port is out of range.
unsigned char getPort(unsigned short addr, unsigned char port);

#endif