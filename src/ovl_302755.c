extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_302755(int a)
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
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
L3D:
        mov dx,0xf047
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
        jz short $+58
        ja short $+62
        sub al,0x8
        jz short $+12
        sub al,0xb
        jz short $+20
        sub al,0x19
        jz short $+38
        jmp short $+48
L67:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-41
        nop
L73:
        mov ax,0x195
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1b
        jmp short $-74
L89:
        mov ax,0x1c
        jmp short $-79
        nop
L8F:
        mov ax,0x1d
        jmp short $-85
        nop
L95:
        xor ax,ax
L97:
    }
}
