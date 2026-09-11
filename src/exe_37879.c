extern int __near mn5A1E;
extern char __near mb0020;
void far helper_0(void);
int far exe_37879(void)
{
    _asm {
        mov es, mn5A1E
        cmp byte ptr es:mb0020,0x0
        jz short $+24
        mov ax,0x20
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x1
        jmp short $+5
        nop
L22:
        xor ax,ax
L24:
        retf
    }
}
