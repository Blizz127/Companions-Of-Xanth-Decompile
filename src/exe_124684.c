extern int __near mn0BA4;
extern int __near mn0BA6;
void far helper_0(void);
int far exe_124684(void)
{
    _asm {
        push bx
        push es
        call far ptr helper_0
        mov ax,0x1dc1
        mov es,ax
        mov ax,0x0
        cmp word ptr es:mn0BA4,0x0
        jz short $+28
        mov bx,es:mn0BA6
        mov ah,0x3e
        int 0x21
        jc short $+14
        mov word ptr es:mn0BA4,0x0
        mov ax,0x0
        jmp short $+5
L2E:
        mov ax,0xffff
L31:
        pop es
        pop bx
        retf
    }
}
