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
int far ovl_313730(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+76
        jmp L2E7
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L2E7
L1E:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
L45:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L52:
        mov ax,0x1
        jmp L2E9
        nop
L59:
        mov ax,mn6A06
        cmp ax,0x4d
        jnz short $+5
        jmp L209
L64:
        jna short $+5
        jmp L2E7
L69:
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+116
        sub al,0x19
        jnz short $+5
        jmp L151
L78:
        sub al,0x19
        jnz short $+5
        jmp L1F1
L7F:
        jmp L2E7
        nop
L83:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0xb
        jmp L194
L9D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xc
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_4
LDC:
        add sp,0x4
        jmp L52
        nop
LE3:
        mov ax,0xe
        push ax
        mov ax,0x1be
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x5
        jmp short $+6
        nop
LFD:
        mov ax,0x6
L100:
        mov dx,0xf049
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3a3d
        push ds
        push ax
        call far ptr helper_1
        add sp,0xc
        mov ax,0xa
        push ax
        mov ax,0x1be
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+9
        mov ax,0x3a46
        mov dx,ds
        jmp short $+5
L13F:
        xor ax,ax
        cwd
L142:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x7
        jmp L266
        nop
L151:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x8
        jmp L266
L17D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+18
        mov ax,0x9
L194:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        jmp LDC
L1A1:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov ax,0x3a49
        push ds
        push ax
        call far ptr helper_6
        jmp LDC
        nop
L1F1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xd
        jmp short $+96
        nop
L209:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
        jmp short $+52
        nop
L235:
        cmp word ptr mn6A02,0x1c2
        jz short $+102
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_7
        add sp,0x4
        or ax,ax
        jnz short $+40
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
L266:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L52
        nop
L277:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x10
        jmp L45
L2A1:
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_8
        add sp,0x6
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        jmp LDC
        nop
L2E7:
        xor ax,ax
L2E9:
    }
}
