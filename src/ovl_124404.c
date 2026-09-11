extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_124404(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1F5
L0B:
        mov ax,mn6A06
        cmp ax,0x4a
        jnz short $+5
        jmp L191
L16:
        jna short $+5
        jmp L1F5
L1B:
        cmp al,0x2c
        jz short $+32
        ja short $+14
        sub al,0x8
        jz short $+26
        sub al,0xb
        jz short $+44
        jmp L1F5
        nop
L2D:
        sub al,0x38
        jz short $+42
        sub al,0xd
        jz short $+72
        sub al,0x2
        jz short $+90
        jmp L1F5
        nop
L3D:
        mov ax,0x60
L40:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
L4A:
        mov sp,bp
L4C:
        mov ax,0x1
        jmp L1F7
        nop
L53:
        mov ax,0x57
        jmp short $-22
        nop
L59:
        cmp word ptr mn6A02,0x83
        jz short $+5
        jmp L1F5
L64:
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x4d
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp L1F7
        nop
L7B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x58
        jmp short $-79
L91:
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x59
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        mov ax,0x5a
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0xbb8
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        mov ax,0x5b
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        mov ax,0x5c
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0xbb8
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        mov ax,0x5d
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x7d0
        push ax
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x5e
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        jmp L4A
L191:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x26e2
        jmp short $+5
L1A9:
        mov ax,0x26e7
L1AC:
        push ds
        push ax
        mov ax,0x5f
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        mov sp,bp
        or ax,ax
        jz short $+19
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        jmp L4A
        nop
L1E1:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
        jmp L4C
        nop
L1F5:
        xor ax,ax
L1F7:
    }
}
