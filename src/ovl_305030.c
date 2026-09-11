extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_305030(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp LC9
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC9
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+24
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x3b
        jmp short $+23
L43:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
L58:
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x1
        jmp short $+99
        nop
L6B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+64
        ja short $+86
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+30
        sub al,0x19
        jnz short $+74
L81:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x39
        jmp short $-62
        nop
L99:
        mov ax,0x1a7
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x38
        jmp short $-86
        nop
LB1:
        mov ax,0x1a7
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x3a
        jmp short $-110
        nop
LC9:
        xor ax,ax
LCB:
    }
}
