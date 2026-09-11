extern int __near mn4D38;
void far helper_0(void);
int far exe_91803(void)
{
    _asm {
        push word ptr mn4D38
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jnl short $+6
        xor ax,ax
        jmp short $+10
L14:
        mov bx,ax
        add bx,ax
        mov ax,[bx+0x637c]
L1C:
        retf
    }
}
