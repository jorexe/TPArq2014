#include "../../include/drivers/video.h"

/* 		X			DIM_MAXCOLS					*/
/*  -------------------							*/
/*  |											*/
/* Y|											*/
/*  |											*/
/*  |											*/
/* DIM_MAXROWS									*/

// char * video = (char *)VIDEO_PORT;
position cursor = { 0 , 0 };

int printChar(byte character) {
    switch (character) {
        case '\n': return newLine();
        case '\t': return incCursor();
        case '\b': {
            if(decCursor()) {
                setChar(cursor, ' ');
                return 1;
            }
            return 0;
        }
        default: {
            setChar(cursor, character);
            if(!incCursor())
                return 0;
            return 1;
        }
    }
    return 1;
}

int setCursor(int x, int y) {
    if(x < DIM_MAXCOLS && y < DIM_MAXROWS) {
        cursor.x = x;
        cursor.y = y;
        set_cursor(cursor.x, cursor.y);
        return 1;
    }
    if(x < DIM_MAXCOLS){
    	cursor.y = DIM_MAXROWS - 1;
    	cursor.x = 0;
    	scrollScreen();
    	return 1;
    }
    return 0;
}

int incCursor(){
	if(cursor.x == DIM_MAXCOLS - 1)
		return setCursor(0, cursor.y + 1);
	return setCursor(cursor.x + 1, cursor.y);
}

int decCursor(){
	if(cursor.x == 0){
		if(cursor.y > 0)
			return setCursor(DIM_MAXCOLS - 1, cursor.y - 1);
		return 0; /*Esto podría salvarnos de algún inconveniente*/
	}
	return setCursor(cursor.x - 1, cursor.y);
}

int newLine(){
	return setCursor(0, cursor.y + 1);
}

// int clearScreen(){
// 	int i = 0;
// 	while(i<DIM_VECTOR){
// 		video[i] = CHAR_BLANK;
// 		i++;
// 		video[i] = WHITE_TXT; /*PONELE*/
// 		i++;
// 	}
// 	return 1;
// }

// void setChar(position pos, byte ascii) {
//     video[positionToIndex(pos.x,pos.y)*2] = ascii;
//     return;
// }

int positionToIndex(int x, int y){
	if(y == 0)
		return x;
	return y-1 * DIM_MAXCOLS + x;
}

// int scrollScreen(){
// 	int j = 0;
// 	int i = 0;
// 	while(j<DIM_MAXROWS-1){
// 		i = 0;
// 		while(i<DIM_MAXCOLS){
// 			video[positionToIndex(i,j)] = video[positionToIndex(i,j+1)];
// 		}
// 	}
// 	i=0;
// 	while(i<DIM_MAXCOLS){
// 			video[positionToIndex(i,j)] = CHAR_BLANK;
// 	}
// 	setCursor(0,DIM_MAXROWS - 1);
// 	return 1;
// }