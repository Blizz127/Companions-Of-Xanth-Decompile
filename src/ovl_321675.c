extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_321675(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L8B
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+116
        ja short $+120
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+34
        jmp short $+104
L25:
        sub al,0x34
        jz short $+34
        sub al,0x10
        jz short $+84
        jmp short $+94
L2F:
        mov ax,0x14
L32:
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_0
L3C:
        mov sp,bp
        mov ax,0x1
        jmp short $+76
L43:
        mov ax,0x12
        jmp short $-20
        nop
L49:
        mov ax,0x16
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        call far ptr helper_1
        mov ax,0x3ac4
        push ds
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1770
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x1de
        push ax
        call far ptr helper_4
        jmp short $-65
L7F:
        mov ax,0x13
        jmp short $-80
        nop
L85:
        mov ax,0x15
        jmp short $-86
        nop
L8B:
        xor ax,ax
L8D:
    }
}
