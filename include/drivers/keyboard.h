#ifndef _keyboard_
#define _keyboard_

#define NOP 0x00
#define ESC 0x01
#define BKSP 0x0E
#define CTRL 0x1D

#define MAKE_SHIFT_L 0x2A
#define MAKE_SHIFT_R 0x36
#define BREAK_SHIFT_L 0xAA
#define BREAK_SHIFT_R 0xB6

int scanCodeToAscii(int);
void specialKey(int);

#endif
