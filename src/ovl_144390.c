extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
int far ovl_144390(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+95
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+86
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x10
L3D:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+33
        nop
L4F:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+11
        jmp short $+15
        nop
L5F:
        mov ax,0xe
        jmp short $-37
        nop
L65:
        mov ax,0xf
        jmp short $-43
        nop
L6B:
        xor ax,ax
L6D:
    }
}
