# W65C02

In this project I'am experimenting with my W65C02 microprocessor and create libraries for different components from scratch. I'am using the W65C22 from the 6502 kit from [Ben Eater](https://www.youtube.com/@BenEater) and assemybled it in the same way than in his explanation videos. 

## Hardware

The W65C02 is currently assembled in this way:
<img width="1894" alt="6502" src="https://eater.net/schematics/6502-serial.png" />
(image from [eater.net](https://eater.net/6502))

My currently on the breadboard assembled W65C02 is a bit deviating from the schematic. Instead of buttons red leds are assembled on PA 0 to PA 4.

## Address spaces

|     Component     |  Address space  |
| ----------------- | --------------- |
| HM62256B (RAM)    | 0x0    - 0x3FFF |
| W65C22 (VIA)      | 0x6000 - 0x6003 |
| AT28C256 (EEPROM) | 0x8000 - 0xFFFF |
