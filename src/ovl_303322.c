extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_303322(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp LA5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA5
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+24
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x27
        jmp short $+23
L43:
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x28
L58:
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L65:
        mov ax,0x1
        jmp short $+63
        nop
L6B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+46
        ja short $+50
        sub al,0x13
        jz short $+8
        sub al,0x7
        jz short $+22
        jmp short $+40
L7F:
        mov ax,0x25
L82:
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-42
L91:
        mov ax,0x7
        push ax
        call far ptr helper_3
        add sp,0x2
        jmp short $-56
L9F:
        mov ax,0x26
        jmp short $-32
        nop
LA5:
        xor ax,ax
LA7:
    }
}
