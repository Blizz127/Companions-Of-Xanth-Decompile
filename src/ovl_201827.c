extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_201827(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp L91
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+124
        xor ax,ax
        push ax
        push word ptr mn6A02
        mov ax,0x2c
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp short $+106
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+90
        ja short $+94
        cmp al,0x2c
        jz short $+28
        ja short $+12
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+38
        jmp short $+78
L45:
        sub al,0x38
        jz short $+38
        sub al,0x2
        jz short $+28
        sub al,0xa
        jz short $+30
        jmp short $+64
L53:
        mov ax,0x2e
L56:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+46
L67:
        mov ax,0x2d
        jmp short $-20
        nop
L6D:
        push word ptr mn0256
        mov ax,0x11
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x2f
        jmp short $-45
L85:
        mov ax,0x30
        jmp short $-50
        nop
L8B:
        mov ax,0x31
        jmp short $-56
        nop
L91:
        xor ax,ax
L93:
    }
}
