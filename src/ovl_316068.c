extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_316068(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp L95
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+128
        push word ptr mn6A02
        mov ax,0x2
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
        mov ax,0x3b
L3D:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
L47:
        mov sp,bp
        mov ax,0x1
        jmp short $+75
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+52
        ja short $+62
        sub al,0x8
        jz short $+12
        sub al,0xb
        jz short $+14
        sub al,0x19
        jz short $+16
        jmp short $+48
L67:
        mov ax,0x3a
        jmp short $-45
        nop
L6D:
        mov ax,0x38
        jmp short $-51
        nop
L73:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x39
        jmp short $-74
L89:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-75
        nop
L95:
        xor ax,ax
L97:
    }
}
