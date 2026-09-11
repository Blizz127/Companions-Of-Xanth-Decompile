extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_88759(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+83
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+69
        ja short $+73
        cmp al,0x2c
        jz short $+25
        ja short $+13
        sub al,0x8
        jz short $+19
        sub al,0xb
        jz short $+31
        jmp short $+57
        nop
L23:
        sub al,0x3e
        jz short $+52
        sub al,0x6
        jz short $+36
        jmp short $+46
L2D:
        push word ptr mn6A04
        call far ptr helper_0
L36:
        mov sp,bp
        mov ax,0x1
        jmp short $+32
L3D:
        mov ax,0x39
L40:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        jmp short $-20
        nop
L4D:
        mov ax,0x3a
        jmp short $-16
        nop
L53:
        mov ax,0x3b
        jmp short $-22
        nop
L59:
        xor ax,ax
L5B:
    }
}
