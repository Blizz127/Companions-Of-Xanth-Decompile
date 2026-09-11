extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_148700(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+79
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+65
        ja short $+69
        cmp al,0x2c
        jz short $+23
        ja short $+13
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+33
        jmp short $+53
        nop
L23:
        sub al,0x38
        jz short $+6
        sub al,0xc
        jnz short $+44
L2B:
        mov ax,0x64e
        push ax
        mov ax,0x351
        push ax
        call far ptr helper_0
L38:
        mov sp,bp
        mov ax,0x1
        jmp short $+26
L3F:
        mov ax,0xb
L42:
        mov dx,0xf018
        push dx
        push ax
        call far ptr helper_1
        jmp short $-20
        nop
L4F:
        mov ax,0xc
        jmp short $-16
        nop
L55:
        xor ax,ax
L57:
    }
}
