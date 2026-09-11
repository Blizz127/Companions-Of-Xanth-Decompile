extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_155523(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+119
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+110
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x50
L2B:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L37:
        mov ax,0x1
        jmp short $+75
        nop
L3D:
        mov ax,mn6A06
        sub ax,0x11
        jz short $+18
        dec ax
        dec ax
        jz short $+36
        sub ax,0x31
        jc short $+55
        sub ax,0x1
        jna short $+44
        jmp short $+48
L55:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x4f
        jmp short $-62
L6B:
        mov ax,0x4d
L6E:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-68
L7D:
        mov ax,0x4e
        jmp short $-18
        nop
L83:
        xor ax,ax
L85:
    }
}
