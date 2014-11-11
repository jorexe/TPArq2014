#include "../include/interrupts.h"

void int_08() {

}

void int_09(int scancode) {
	int c = scanCodeToAscii(scanCode);
    if(c != NOP) {
        enqueueBuffer(c, &stdinBuffer);
    }
}