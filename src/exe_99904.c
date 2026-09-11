extern char __near mb4E9E;

int far exe_99904(int a)
{
    _asm {
        sub sp,0x2
        test byte ptr mb4E9E,0x2
        jz short $+7
        xor ax,ax
        jmp short $+16
        nop
L0F:
        mov ax,0xb
        int 0x33
        or cx,dx
        mov [bp-0x2],cx
        mov ax,[bp-0x2]
L1C:
    }
}
