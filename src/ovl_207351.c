extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_207351(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp L91
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+124
        push word ptr mn6A04
        push word ptr mn6A02
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp short $+105
        nop
L2D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+72
        ja short $+92
        cmp al,0x2c
        jz short $+22
        ja short $+12
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+50
        jmp short $+76
L47:
        sub al,0x38
        jz short $+6
        sub al,0xc
        jnz short $+68
L4F:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x43
L63:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short $+33
        nop
L75:
        mov ax,0x42
        jmp short $-21
        nop
L7B:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x44
        jmp short $-44
L91:
        xor ax,ax
L93:
    }
}
