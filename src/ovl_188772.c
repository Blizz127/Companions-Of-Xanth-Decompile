extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_188772(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+87
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+78
        mov ax,0x9
L1A:
        mov dx,0xf020
        push dx
        push ax
        call far ptr helper_0
L24:
        mov sp,bp
        mov ax,0x1
        jmp short $+60
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+44
        ja short $+48
        sub al,0x8
        jz short $+14
        sub al,0xb
        jz short $+16
        sub al,0x7
        jz short $+18
        sub al,0x12
        jnz short $+32
L45:
        mov ax,0x7
        jmp short $-46
        nop
L4B:
        mov ax,0x6
        jmp short $-52
        nop
L51:
        mov ax,0x3
        push ax
        call far ptr helper_1
        jmp short $-54
        nop
L5D:
        mov ax,0x8
        jmp short $-70
        nop
L63:
        xor ax,ax
L65:
    }
}
