#include "../../include/drivers/keyboard.h"

int shifted = 0;

char scanCodeToAsciiTable[0xFF] =
{    /*	 0    1	   2    3    4    5    6    7    8    9    A    B    C    D    E     F    */
/*0*/	NOP, ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', NOP, '\b', '\t',

/*1*/	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', NOP, '+', '\n', NOP, 'a', 's',

/*2*/	'd', 'f', 'g', 'h', 'j', 'k', 'l', NOP, '{', '}', NOP, '<', 'z', 'x', 'c', 'v',

/*3*/	'b', 'n', 'm', ',', '.', '-', NOP, '*', NOP, ' ', NOP, 0xB3, NOP, NOP, NOP, NOP,

/*4*/	NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, 0xC1, NOP, '-', 0xB4, NOP, 0xC3, '+', NOP,

/*5*/	0xC2, NOP, 0xDC, 0xB2, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP

};

char scanCodeToAsciiShiftedTable[0xFF] =
{
     /*	 0    1	   2    3    4    5    6    7    8    9    A    B    C    D    E     F    */
/*0*/	NOP, ESC, '!', '"', '#', '$', '%', '&', '/', '(', ')', '=', '?', NOP, '\b', NOP,
    
/*1*/	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', NOP, '*', '\n', NOP, 'A', 'S',
    
/*2*/	'D', 'F', 'G', 'H', 'J', 'K', 'L', NOP, '[', ']', NOP, '>', 'Z', 'X', 'C', 'V',
    
/*3*/	'B', 'N', 'M', ';', ':', '_', NOP, NOP, NOP, ' ', NOP, 0xB3, NOP, NOP, NOP, NOP,
    
/*4*/	NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, 0xC1, NOP, '-', 0xB4, NOP, 0xC3, '+', NOP,
    
/*5*/	0xC2, NOP, 0xDC, 0xB2, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP
    
};

int scanCodeToAscii(int scanCode) {
    specialKey(scanCode);
    if(shifted == 1)
        return scanCodeToAsciiShiftedTable[scanCode];
    return scanCodeToAsciiTable[scanCode];
}

void specialKey(int scanCode) {
    if(scanCode == MAKE_SHIFT_L || scanCode == MAKE_SHIFT_R) /* makecodes */
        shifted = 1;
    if(scanCode == BREAK_SHIFT_L || scanCode == BREAK_SHIFT_R) /* breakcodes */
        shifted = 0;
    return ;
}