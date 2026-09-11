extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_123462(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+97
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+88
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x45
L2B:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L37:
        mov ax,0x1
        jmp short $+53
        nop
L3D:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+24
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x44
        jmp short $-46
L5B:
        mov ax,0x43
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-52
L6D:
        xor ax,ax
L6F:
    }
}
