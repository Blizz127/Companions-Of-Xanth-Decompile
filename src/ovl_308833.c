extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_308833(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+123
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+79
        ja short $+113
        cmp al,0x13
        jz short $+55
        ja short $+13
        sub al,0x7
        jz short $+21
        dec al
L1E:
        jz short $+33
        jmp short $+97
        nop
L23:
        sub al,0x2c
        jz short $+26
        sub al,0xc
        jz short $+22
        sub al,0xc
        jmp short $-15
L2F:
        mov ax,0x1
        push ax
        call far ptr helper_0
L38:
        mov sp,bp
L3A:
        mov ax,0x1
        jmp short $+70
L3F:
        push word ptr mn6A04
        call far ptr helper_1
        jmp short $-16
        nop
L4B:
        mov ax,0x12
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-33
L5D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x13
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $-69
L81:
        xor ax,ax
L83:
    }
}
