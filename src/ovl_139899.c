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
void far helper_7(void);
void far helper_8(void);
int far ovl_139899(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp L14F
L12:
        jmp L2F5
L15:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L2F5
L20:
        cmp word ptr mn6A04,0xa4
        jz short $+5
        jmp LDB
L2B:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+40
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x28
L54:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L149
        nop
L65:
        mov ax,0xe
        push ax
        mov ax,0xa3
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+26
        mov ax,0xa3
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x29
        jmp short $-58
        nop
L91:
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
        mov ax,0x2a
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x6
        jmp short $+112
LDB:
        cmp word ptr mn6A04,0xa6
        jz short $+52
        cmp word ptr mn6A04,0xa7
        jz short $+44
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c
        jmp short $+42
        nop
L115:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2b
L13C:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
L149:
        mov ax,0x1
        jmp L2F7
L14F:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L2D5
L15A:
        jna short $+5
        jmp L2F5
L15F:
        sub al,0x8
        jz short $+26
        sub al,0xb
        jnz short $+5
        jmp L207
L16A:
        sub al,0x19
        jnz short $+5
        jmp L217
L171:
        sub al,0x18
        jnz short $+5
        jmp L2BD
L178:
        jmp L2F5
L17B:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x24
        jmp L54
L1A7:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x25
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0x295f
        push ds
        push ax
        call far ptr helper_7
        add sp,0x4
        mov ax,0x2967
L1F9:
        push ds
        push ax
        call far ptr helper_7
L200:
        add sp,0x4
        jmp L149
        nop
L207:
        mov ax,0x1f
L20A:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        jmp short $-20
        nop
L217:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
        jmp L54
L243:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        push word ptr mn6A04
        mov ax,0xa4
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x23
        mov dx,0xf010
        jmp short $+7
L281:
        mov ax,0x294e
        mov dx,ds
L286:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0x2957
        jmp L1F9
        nop
L2BD:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x20
        jmp L54
L2D5:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x26
        jmp L20A
L2EF:
        mov ax,0x27
        jmp L20A
L2F5:
        xor ax,ax
L2F7:
    }
}
