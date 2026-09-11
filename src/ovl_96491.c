extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_96491(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+71
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+57
        ja short $+61
        sub al,0x13
        jz short $+9
        sub al,0x31
        jz short $+25
        jmp short $+51
        nop
L1D:
        mov ax,0x1a
L20:
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+32
L31:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x1b
        jmp short $-37
L47:
        mov ax,0x1c
        jmp short $-42
        nop
L4D:
        xor ax,ax
L4F:
    }
}
