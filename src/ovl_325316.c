extern int __near mn6A06;
void far helper_0(void);
int far ovl_325316(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+69
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+60
        mov ax,0x8
L1A:
        mov dx,0xf04d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+42
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+26
        ja short $+30
        sub al,0x13
        jz short $+8
        sub al,0x31
        jz short $+10
        jmp short $+20
L3F:
        mov ax,0x5
        jmp short $-40
        nop
L45:
        mov ax,0x6
        jmp short $-46
        nop
L4B:
        mov ax,0x7
        jmp short $-52
        nop
L51:
        xor ax,ax
L53:
    }
}
