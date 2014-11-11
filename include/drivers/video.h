#ifndef _video_
#define _video_

#include "../defs.h"
#include "../kc.h"
/* #include "../lib/stdio.h" */

/*DEFINICIONES*/

#define VIDEO_PORT = 0xB8000
#define ERROR = -1

// /*Caracteres*/
#define CHAR_BLANK ' '
#define TAB_SPACES 4

/*Dimensiones*/
#define DIM_MAXROWS 25
#define DIM_MAXCOLS 80
#define DIM_VIDEOROWS = DIM_MAXROWS * 2 
#define DIM_VIDEOCOLS = DIM_MAXCOLS * 2

#define DIM_VECTOR = DIM_MAXCOLS * DIM_MAXROWS
#define DIM_VIDEOVECTOR = VECTOR * 2

/*typedef unsigned char byte;*/

typedef struct pos{
	int x;
	int y;
} position;

/*Funciones*/
extern void set_cursor(byte row, byte column);
int printChar(unsigned char character);
int setCursor(int x, int y);
int incCursor();
int decCursor();
int newLine();
int clearScreen();
void setChar(position pos, byte ascii);
int positionToIndex(int x, int y);
int scrollScreen();
#endif