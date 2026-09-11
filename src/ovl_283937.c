extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_283937(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LE9
L0F:
        jmp L12B
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+5
        jmp L12B
L23:
        mov ax,mn6A04
        sub ax,0x124
        jz short $+34
        sub ax,0x52
        jz short $+49
        dec ax
        jz short $+100
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x12
        jmp LD6
        nop
L4B:
        mov ax,0x11
L4E:
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp LE3
        nop
L5F:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp short $+80
L95:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        jmp short $+24
        nop
LC1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x10
LD6:
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
LE3:
        mov ax,0x1
        jmp short $+71
        nop
LE9:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+54
        ja short $+58
        cmp al,0x2c
        jz short $+36
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+20
        jmp short $+42
L103:
        sub al,0x38
        jz short $+26
        sub al,0xc
        jz short $+22
        jmp short $+32
L10D:
        mov ax,0xc
        jmp L4E
L113:
        mov ax,0x9
        jmp L4E
L119:
        mov ax,0xb
        jmp L4E
L11F:
        mov ax,0xa
        jmp L4E
L125:
        mov ax,0xd
        jmp L4E
L12B:
        xor ax,ax
L12D:
    }
}
