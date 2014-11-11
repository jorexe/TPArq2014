#include "./drivers/keyboard.h"
#include "defs.h"
#include "kasm.h"

#ifndef _ints_
#define _ints_

/* Interrupcion del Timer Tick */
void int_08(void);

/* Interrupcion de Teclado */
void int_09(int);

#endif
