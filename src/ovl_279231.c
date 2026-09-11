extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_279231(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LFF
L0F:
        jmp L1C3
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x10
        jz short $+5
        jmp L1C3
L23:
        cmp word ptr mn6A04,0x16e
        jz short $+5
        jmp LC5
L2E:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+44
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        jmp LEC
        nop
L6B:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        mov ax,0x4e
        push ax
        push word ptr mn6A04
        call far ptr helper_4
LC0:
        add sp,0x4
        jmp short $+54
LC5:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f
LEC:
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
LF9:
        mov ax,0x1
        jmp L1C5
LFF:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1B3
L10A:
        jna short $+5
        jmp L1C3
L10F:
        cmp al,0x2c
        jz short $+28
        ja short $+14
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+42
        jmp L1C3
        nop
L121:
        sub al,0x38
        jz short $+128
        sub al,0xc
        jz short $+124
        jmp L1C3
        nop
L12D:
        xor ax,ax
        push ax
        mov ax,0x16b
        push ax
        push word ptr mn6A06
        call far ptr helper_5
        add sp,0x6
        jmp L1C5
        nop
        nop
L145:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1a
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        push word ptr mn6A04
        mov ax,0x16e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp LF9
L17E:
        mov ax,0x16e
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp LF9
L1A3:
        mov ax,0x1c
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_2
        jmp LC0
L1B3:
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x2
        jmp LF9
        nop
L1C3:
        xor ax,ax
L1C5:
    }
}
