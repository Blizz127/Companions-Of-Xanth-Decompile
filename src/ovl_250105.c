extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn02D6;
void far helper_0(void);
void far helper_1(void);
int far ovl_250105(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+58
        jmp LAB
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LAB
L1E:
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x31
L33:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L40:
        mov ax,0x1
        jmp short $+106
        nop
        nop
L47:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+88
        ja short $+92
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+32
        jmp short $+76
L61:
        sub al,0x38
        jz short $+32
        sub al,0xc
        jz short $+28
        jmp short $+66
L6B:
        mov ax,0x2e
L6E:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-59
L7D:
        mov ax,0x2d
        jmp short $-18
        nop
L83:
        inc word ptr mn02D6
        cmp word ptr mn02D6,0x1
        jng short $+9
        mov ax,0x3433
        mov dx,ds
        jmp short $+5
L95:
        xor ax,ax
        cwd
L98:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x2f
        jmp short $-112
LA5:
        mov ax,0x30
        jmp short $-58
        nop
LAB:
        xor ax,ax
LAD:
    }
}
