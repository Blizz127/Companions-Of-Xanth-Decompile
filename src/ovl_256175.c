extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_256175(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+107
        jmp L91
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+124
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+105
        push word ptr mn6A04
        mov ax,0x26
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
L62:
        mov dx,0xf042
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short $+34
        nop
        nop
L75:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+11
        jmp short $+15
        nop
L85:
        mov ax,0x10
        jmp short $-38
        nop
L8B:
        mov ax,0x11
        jmp short $-44
        nop
L91:
        xor ax,ax
L93:
    }
}
