extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_69190(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L12F
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L117
L16:
        jna short $+5
        jmp L12F
L1B:
        sub al,0x13
        jz short $+20
        sub al,0x2
        jz short $+78
        sub al,0x13
        jnz short $+5
        jmp LCD
L2A:
        sub al,0x12
        jz short $+5
        jmp L12F
L31:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+7
        mov ax,0x23
        jmp short $+22
L49:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x24
L5D:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
L69:
        mov ax,0x1
        jmp L131
L6F:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x25
        jmp short $+96
        nop
L99:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x26
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
LC8:
        add sp,0x4
        jmp short $-98
LCD:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+40
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x27
LF6:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L69
        nop
L107:
        mov ax,0x28
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_2
        jmp short $-76
        nop
L117:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x29
        jmp short $-54
        nop
L12F:
        xor ax,ax
L131:
    }
}
