extern int __near mn0006;
extern int __near mn0008;
extern int __near mn000A;
extern char __near mb0018;
extern int __near mn0010;
extern int __near mn000C;
extern int __near mn000E;
void far helper_0(void);
int far exe_396(void)
{
    _asm {
        push ax
        push dx
        xor ax,ax
        call far ptr helper_0
        mov word ptr cs:mn0006,0x1
        mov cs:mn0008,ax
        mov cs:mn000A,ax
        mov byte ptr cs:mb0018,0x0
        mov ax,ds
        mov cs:mn0010,ax
        push es
        mov ah,0x35
        mov al,0x8
        int 0x21
        mov cs:mn000C,bx
        mov word ptr cs:mn000E,es
        pop es
        push ds
        mov ah,0x25
        mov al,0x8
        mov dx,0xc8
        mov bx,cs
        mov ds,bx
        int 0x21
        pop ds
        pop dx
        pop ax
        retf
    }
}
