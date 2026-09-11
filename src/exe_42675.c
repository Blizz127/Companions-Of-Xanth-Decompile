extern int __near mn0056;
void far helper_0(void);
void far helper_1(void);
int far exe_42675(void)
{
    _asm {
        mov ax,0xb8
        push ax
        mov ax,0x6
        push ax
        call far ptr helper_0
        add sp,0x4
        xor ax,ax
        push ax
        cmp word ptr mn0056,0x1
        jnz short $+8
        mov ax,0x18
        jmp short $+6
        nop
L20:
        mov ax,0x17
L23:
        push ax
        call far ptr helper_1
        add sp,0x4
        retf
    }
}
