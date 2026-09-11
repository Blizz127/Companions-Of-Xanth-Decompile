extern int __near mn6A06;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_159336(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+115
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x19
        jnz short $+106
        mov ax,0x5a02
        push ax
        mov ax,0x205
L1E:
        push ax
        call far ptr helper_0
L24:
        mov sp,bp
L26:
        mov ax,0x1
        jmp short $+88
L2B:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+37
        jmp short $+71
        nop
L3B:
        push word ptr mn0256
        mov ax,0x1
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_2
        jmp short $-53
L5B:
        mov ax,mn0256
        sub ax,0x5b
        jz short $+12
        mov ax,0x5a02
        push ax
        mov ax,0x203
        jmp short $-76
        nop
L6D:
        mov ax,0x5a02
        push ax
        mov ax,0x204
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $-87
L7F:
        xor ax,ax
L81:
    }
}
