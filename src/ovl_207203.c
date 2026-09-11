extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_207203(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+127
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+118
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
        mov ax,0x41
L3D:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+65
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+48
        ja short $+52
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+20
        jmp short $+36
L69:
        sub al,0x38
        jz short $+20
        sub al,0xc
        jz short $+16
        jmp short $+26
L73:
        mov ax,0x3e
        jmp short $-57
        nop
L79:
        mov ax,0x3d
        jmp short $-63
        nop
L7F:
        mov ax,0x3f
        jmp short $-69
        nop
L85:
        mov ax,0x40
        jmp short $-75
        nop
L8B:
        xor ax,ax
L8D:
    }
}
