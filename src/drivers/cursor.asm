; Material obtenido de:
; http://wiki.osdev.org/Text_Mode_Cursor#Moving_the_Cursor_without_the_BIOS
; Set cursor position (text mode 80x25)
; @param BL The row on screen, starts from 0
; @param BH The column on screen, starts from 0
;=============================================================================
GLOBAL set_cursor

set_cursor:     
                push ebp
                mov ebp,esp
                pushf
                pushad
                                
                ;unsigned short position = (row*80) + col;
                ;AX will contain 'position'
                
                mov bl,byte[ebp + 8]
                mov bh,byte[ebp + 12]
                mov ax,bx
                and ax,0ffh             ;set AX to 'row'
                mov cl,80   
                mul cl                  ;row*80
 
                mov cx,bx               
                shr cx,8                ;set CX to 'col'
                add ax,cx               ;+ col
                mov cx,ax               ;store 'position' in CX
 
                ;cursor LOW port to vga INDEX register
                mov al,0fh             
                mov dx,3d4h             ;VGA port 3D4h
                out dx,al             
 
                mov ax,cx               ;restore 'postion' back to AX  
                mov dx,3d5h             ;VGA port 3D5h
                out dx,al               ;send to VGA hardware
 
                ;cursor HIGH port to vga INDEX register
                mov al,0eh
                mov dx,3d4h             ;VGA port 3D4h
                out dx,al
 
                mov ax,cx               ;restore 'position' back to AX
                shr ax,8                ;get high byte in 'position'
                mov dx,3d5h             ;VGA port 3D5h
                out dx,al               ;send to VGA hardware
                popad
                popf
                mov esp,ebp
                pop ebp
                ret
