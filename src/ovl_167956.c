extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_167956(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+105
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+91
        ja short $+95
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+65
        sub al,0x19
        jz short $+9
        sub al,0x18
        jz short $+67
        jmp short $+77
        nop
L25:
        cmp word ptr mn6A06,0x2c
        jnz short $+7
        mov ax,0x2c5c
        jmp short $+5
L31:
        mov ax,0x2c61
L34:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c67
        push ds
L4C:
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+26
L59:
        mov ax,0x10
L5C:
        mov dx,0xf01c
        push dx
        jmp short $-20
        nop
L63:
        mov ax,0x11
        jmp short $-10
        nop
L69:
        mov ax,0x12
        jmp short $-16
        nop
L6F:
        xor ax,ax
L71:
    }
}
