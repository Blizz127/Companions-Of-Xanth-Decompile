extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_101012(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+113
        jmp LDF
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LDF
L1A:
        mov ax,0xc
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+58
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x29
L53:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short $+127
        nop
L65:
        mov ax,0x6e
        push ax
        push word ptr mn6A04
L6D:
        push word ptr mn6A06
L71:
        call far ptr helper_3
        mov sp,bp
        jmp short $+105
        nop
L7B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+88
        ja short $+92
        cmp al,0x2c
        jz short $+52
        ja short $+12
        sub al,0x13
        jz short $+18
        sub al,0x11
        jz short $+20
        jmp short $+76
L95:
        sub al,0x42
        jz short $+42
        sub al,0x2
        jz short $+48
        jmp short $+66
L9F:
        mov ax,0x25
        jmp short $-79
        nop
LA5:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x27
        jmp short $-102
LBB:
        mov ax,0x28
        jmp short $-107
        nop
LC1:
        xor ax,ax
        push ax
        mov ax,0x6e
        push ax
        jmp short $-91
        nop
LCB:
        xor ax,ax
        push ax
        mov ax,0x6e
        push ax
        mov ax,0x44
        push ax
        jmp short $-101
        nop
LD9:
        mov ax,0x26
        jmp L53
LDF:
        xor ax,ax
LE1:
    }
}
