extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0324;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_79457(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1F7
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1BB
L16:
        jna short $+5
        jmp L1F7
L1B:
        cmp al,0x17
        jz short $+106
        ja short $+14
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+58
        jmp L1F7
        nop
L2D:
        sub al,0x2c
        jz short $+12
        sub al,0x18
        jnz short $+5
        jmp L1A3
L38:
        jmp L1F7
L3B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x22
L4F:
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5B:
        mov ax,0x1
        jmp L1F9
L61:
        mov ax,0xa
        push ax
        mov ax,0x29
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x20
        jmp short $+5
L79:
        mov ax,0x21
L7C:
        mov dx,0xf032
        push dx
        push ax
        mov ax,0x1f
        jmp short $-53
        nop
L87:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2021
        jmp short $+6
        nop
LA1:
        mov ax,0x202d
LA4:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x23
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+43
        mov ax,0x4c
        push ax
        mov ax,0x27
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov byte ptr mb0324,0x0
        jmp L5B
        nop
L105:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x2037
        push ds
        push ax
        call far ptr helper_6
        add sp,0x4
        mov ax,0x4b
        push ax
        mov ax,0x27
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x31
        push ax
        mov ax,0x56
        push ax
        call far ptr helper_7
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L5B
L149:
        mov ax,0xe
        push ax
        mov ax,0x31
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L5B
L160:
        mov byte ptr mb0324,0x1
        mov ax,0xa
        push ax
        mov ax,0x27
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L5B
L17C:
        mov ax,0xa
        push ax
        mov ax,0x27
        push ax
        call far ptr helper_5
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x9
        push ax
        call far ptr helper_8
        add sp,0x6
        jmp L5B
        nop
L1A3:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x24
        jmp L4F
L1BB:
        mov ax,0x203f
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x54
        push ax
        call far ptr helper_0
        add sp,0x8
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x25
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp L5B
L1F7:
        xor ax,ax
L1F9:
    }
}
