extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_88857(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+111
        jmp LB3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB3
L1A:
        cmp word ptr mn6A04,0x4e
        jnz short $+70
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x40
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x40
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $+15
L65:
        mov ax,0x41
L68:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
L72:
        mov sp,bp
        mov ax,0x1
        jmp short $+62
L79:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+46
        ja short $+50
        cmp al,0x29
        jz short $+34
        ja short $+12
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+18
        jmp short $+34
L93:
        sub al,0x2c
        jz short $+6
        sub al,0x18
        jnz short $+26
L9B:
        mov ax,0x3d
        jmp short $-54
        nop
LA1:
        mov ax,0x3c
        jmp short $-60
        nop
LA7:
        mov ax,0x3e
        jmp short $-66
        nop
LAD:
        mov ax,0x3f
        jmp short $-72
        nop
LB3:
        xor ax,ax
LB5:
    }
}
