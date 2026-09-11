extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_176019(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+65
        jmp LC9
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC9
L1A:
        cmp word ptr mn6A04,0xff
        jnz short $+5
        jmp LC9
L25:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x13
L39:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp LCB
L4B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+106
        ja short $+118
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+54
        jmp short $+102
L65:
        sub al,0x38
        jz short $+54
        sub al,0xc
        jz short $+56
        jmp short $+92
L6F:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        cmp word ptr mn6A06,0x2c
        jnz short $+8
        mov ax,0x2eca
        jmp short $+6
        nop
L8D:
        mov ax,0x2ecf
L90:
        push ds
        push ax
        mov ax,0x10
        jmp short $-92
L97:
        mov ax,0xe
        jmp short $-97
        nop
L9D:
        mov ax,0x12
        jmp short $-103
        nop
LA3:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xf
        jmp L39
        nop
LBB:
        call far ptr helper_2
        push dx
        push ax
        mov ax,0x11
        jmp L39
        nop
LC9:
        xor ax,ax
LCB:
    }
}
