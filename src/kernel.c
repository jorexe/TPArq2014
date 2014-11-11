//kernel.c Nuestro kernel ,carga IDT y habilita interrupciones
#include "../include/kasm.h"
#include "../include/defs.h"
#include "../include/shell.h"
#include "../include/kc.h"

DESCR_INT idt[0xA];			/* IDT de 10 entradas*/
IDTR idtr;				/* IDTR */

/**********************************************
kmain() 
Punto de entrada de cóo C.
*************************************************/

kmain() 
{

	int i,num;

/* Borra la pantalla. */ 

	k_clear_screen();


/* CARGA DE IDT */
	setup_IDT_content();

/* Carga de IDTR */
	setup_IDTR();

	_Cli();

	_mascaraPIC1(0xF8); //Habilito timer tick, teclado y PIC2
    _mascaraPIC2(0xEF); //Habilito mouse

	_Sti();

	startShell();
	
}

void setup_IDT_content() {
	//	IRQ0: timer tick
	setup_IDT_entry(&idt[0x08], 0x08, (dword) &_int_08_hand, ACS_INT, 0);
	//	IRQ1: keyboard
	setup_IDT_entry(&idt[0x09], 0x08, (dword) &_int_09_hand, ACS_INT, 0);
	//	IRQ2: int80
	//setup_IDT_entry(&idt[0x80], 0x08, (dword) &_int_80_hand, ACS_INT, 0);
}

void setup_IDTR() {
	idtr.base = 0;
	idtr.base += (dword) &idt;
	idtr.limit = sizeof(idt) - 1;

	_lidt(&idtr);
}