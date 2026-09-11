extern char __near mb4246;
void far helper_0(void);
int far exe_82721(void)
{
    _asm {
        cmp byte ptr mb4246,0x0
        jz short $+21
        mov ax,0x4246
        push ds
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x1
        jmp short $+5
        nop
L1A:
        xor ax,ax
L1C:
        retf
    }
}
