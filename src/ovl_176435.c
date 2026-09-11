extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
int far ovl_176435(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp LA5
L12:
        jmp L54B
L15:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L54B
L20:
        mov ax,mn6A04
        sub ax,0x21
        jz short $+45
        sub ax,0xa7
        jz short $+58
        sub ax,0x13
        jz short $+59
        sub ax,0x84
        jz short $+60
        sub ax,0x37
        jz short $+95
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0x14
L47:
        push ax
L48:
        call far ptr helper_0
        add sp,0x6
        jmp L54D
L53:
        mov ax,0x2d
L56:
        mov dx,0xf00b
        push dx
L5A:
        push ax
        call far ptr helper_1
L60:
        add sp,0x4
        jmp short $+48
L65:
        mov ax,0x2f
        jmp short $-18
        nop
L6B:
        mov ax,0x30
        jmp short $-24
        nop
L71:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2e
L86:
        mov dx,0xf00b
        push dx
L8A:
        push ax
        call far ptr helper_1
        add sp,0x8
L93:
        mov ax,0x1
        jmp L54D
L99:
        push word ptr mn6A02
        push word ptr mn6A04
        jmp L3C7
        nop
LA5:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L545
LB0:
        jna short $+5
        jmp L54B
LB5:
        cmp al,0x14
        jnz short $+5
        jmp L305
LBC:
        ja short $+23
        sub al,0x8
        jz short $+43
        sub al,0x8
        jnz short $+5
        jmp L1A5
LC9:
        sub al,0x3
        jnz short $+5
        jmp L2B1
LD0:
        jmp L54B
LD3:
        sub al,0x2c
        jnz short $+5
        jmp L3CD
LDA:
        sub al,0xc
        jnz short $+5
        jmp L47D
LE1:
        sub al,0xc
        jnz short $+5
        jmp L52B
LE8:
        jmp L54B
LEB:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x1f
        jmp L56
L105:
        mov ax,0x193
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+26
        mov ax,0x195
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x20
        jmp L86
L131:
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2f0b
        jmp short $+6
        nop
L14B:
        mov ax,0x2f17
L14E:
        push ds
        push ax
        mov ax,0x21
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        add ax,0x166
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0x2c
L198:
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        jmp L60
L1A5:
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x26
        jmp L86
L1D1:
        mov ax,0x193
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x27
        jmp L56
L1EB:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+68
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2f1d
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $+16
        nop
L241:
        mov ax,0x2f2c
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
L24E:
        mov ax,0x15
        push ax
        push word ptr mn0256
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x2f30
        jmp short $+5
L267:
        mov ax,0x2f37
L26A:
        push ds
        push ax
        mov ax,0xee
        push ax
        mov cx,0x2
        push cx
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x28
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        xor ax,ax
        push ax
        mov ax,0xed
        push ax
        mov ax,0xee
        push ax
        call far ptr helper_9
        add sp,0x6
        mov ax,0x163
        push ax
        mov ax,0xce
        push ax
        call far ptr helper_6
        jmp L60
L2B1:
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+14
        mov word ptr [bp-0x4],0x19
        mov word ptr [bp-0x2],0xf00b
        jmp short $+41
L2D1:
        mov ax,0x193
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x1a
        mov dx,0xf00b
        jmp short $+7
L2ED:
        mov ax,0x2edf
        mov dx,ds
L2F2:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
L2F8:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x2eeb
        push ds
        jmp L8A
L305:
        mov ax,mn6A02
        sub ax,0x7e
        jz short $+26
        sub ax,0x70
        jz short $+63
        sub ax,0x4e
        jz short $+114
        sub ax,0x5a
        jnz short $+5
        jmp L3BF
L31F:
        mov ax,0x25
        jmp L56
L325:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x24
        jmp short $+98
        nop
L34F:
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+14
        push ax
        push word ptr mn6A02
        mov ax,0x44
        jmp L47
        nop
L36F:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        jmp L86
L387:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x23
L3AE:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp L93
        nop
L3BF:
        push word ptr mn6A04
        push word ptr mn6A02
L3C7:
        mov ax,0x4
        jmp L47
L3CD:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x2ef5
        push ds
        jmp L5A
        nop
L3E9:
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+8
        xor ax,ax
        cwd
        jmp short $+8
        nop
L403:
        mov ax,0x2f04
        mov dx,ds
L408:
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x1d
        jmp short $+5
L427:
        mov ax,0x1e
L42A:
        mov dx,0xf00b
        push dx
        push ax
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        mov ax,0x1c
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        add ax,0x164
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0x8
        jmp L198
L47D:
        cmp word ptr mn6A02,0xd8
        jnz short $+82
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+62
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+18
        push word ptr mn6A02
        mov ax,0xee
        push ax
        push word ptr mn6A06
        jmp L48
        nop
L4BD:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2a
        jmp L86
L4D5:
        push word ptr mn6A04
        mov ax,0xee
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+44
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0xee
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2b
        jmp L3AE
L513:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c
        jmp L86
L52B:
        mov ax,0x193
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+14
        mov ax,0x29
        jmp L56
L545:
        mov ax,0x1b
        jmp L56
L54B:
        xor ax,ax
L54D:
    }
}
