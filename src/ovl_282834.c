extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_282834(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp LCB
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LCB
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
        mov ax,0xa
        jmp short $+23
L43:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
L58:
        mov dx,0xf03f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L65:
        mov ax,0x1
        jmp short $+101
        nop
L6B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+66
        ja short $+88
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+30
        sub al,0x7
        jz short $+32
        sub al,0x12
        jz short $+42
        jmp short $+70
L87:
        mov ax,0x8
L8A:
        mov dx,0xf03f
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-50
L99:
        mov ax,0x6
        jmp short $-18
        nop
L9F:
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x2
        jmp short $-70
LAD:
        mov ax,0x7
        jmp short $-38
        nop
LB3:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x9
        jmp short $-112
        nop
LCB:
        xor ax,ax
LCD:
    }
}
