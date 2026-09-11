extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_162678(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+65
        jmp L93
L0F:
        mov ax,mn6A06
        sub ax,0x19
        jnz short $+126
        mov ax,0x11
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+13
        mov ax,0x5a0f
        push ax
        mov ax,0x3b2
        jmp short $+11
        nop
        nop
L35:
        mov ax,0x5a0f
        push ax
        mov ax,0x3b1
L3C:
        push ax
        call far ptr helper_1
L42:
        add sp,0x4
        mov ax,0x1
        jmp short $+77
        nop
L4B:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+21
        jmp short $+59
        nop
L5B:
        mov ax,0x40
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_2
        jmp short $-38
        nop
L6B:
        mov ax,0x11
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+12
        mov ax,0x5a0f
        push ax
        mov ax,0x3a4
        jmp short $-74
        nop
L89:
        mov ax,0x5a0f
        push ax
        mov ax,0x3b0
        jmp short $-84
        nop
L93:
        xor ax,ax
L95:
    }
}
