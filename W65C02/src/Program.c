#define STA(address, value) ((*(volatile unsigned char *) address) = (value))

void main() {
    STA(0x6003, 0b00011111);
    STA(0x6001, 0b00011111);

    while (1);
}