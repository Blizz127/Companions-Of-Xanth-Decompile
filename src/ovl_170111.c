extern char __near mb032D;
void far helper_0(void);
int far ovl_170111(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+15
        cmp byte ptr mb032D,0x0
        jz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L1C:
        xor ax,ax
L1E:
        retf
    }
}
