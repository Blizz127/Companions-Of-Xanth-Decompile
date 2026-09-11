extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_324422(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA1
L1A:
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
        mov ax,0x27
L40:
        mov dx,0xf04c
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+84
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+68
        ja short $+72
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+28
        sub al,0x19
        jnz short $+60
L67:
        cmp word ptr mn6A06,0x2c
        jnz short $+7
        mov ax,0x3b6d
        jmp short $+5
L73:
        mov ax,0x3b72
L76:
        push ds
        push ax
        mov ax,0x25
        jmp short $-59
L7D:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+7
        mov ax,0x23
        jmp short $-83
L95:
        mov ax,0x24
        jmp short $-88
        nop
L9B:
        mov ax,0x26
        jmp short $-94
        nop
LA1:
        xor ax,ax
LA3:
    }
}
