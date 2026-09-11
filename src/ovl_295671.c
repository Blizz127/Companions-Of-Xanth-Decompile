extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_295671(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA7
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA7
L1A:
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
        mov ax,0x11
L40:
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+90
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+74
        ja short $+78
        cmp al,0x29
        jz short $+56
        ja short $+12
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+40
        jmp short $+62
L6B:
        sub al,0x2c
        jz short $+12
        sub al,0xc
        jz short $+42
        sub al,0xc
        jz short $+38
        jmp short $+48
L79:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xe
        jmp short $-77
L8F:
        mov ax,0xc
        jmp short $-82
        nop
L95:
        mov ax,0x10
        jmp short $-88
        nop
L9B:
        mov ax,0xd
        jmp short $-94
        nop
LA1:
        mov ax,0xf
        jmp short $-100
        nop
LA7:
        xor ax,ax
LA9:
    }
}
