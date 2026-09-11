extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_155851(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+115
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+106
        push word ptr mn6A04
        mov ax,0x26
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
        mov ax,0x59
L3D:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+53
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+36
        ja short $+40
        sub al,0x13
        jz short $+12
        sub al,0x11
        jz short $+14
        sub al,0x20
        jz short $+16
        jmp short $+26
L67:
        mov ax,0x55
        jmp short $-45
        nop
L6D:
        mov ax,0x58
        jmp short $-51
        nop
L73:
        mov ax,0x56
        jmp short $-57
        nop
L79:
        mov ax,0x57
        jmp short $-63
        nop
L7F:
        xor ax,ax
L81:
    }
}
