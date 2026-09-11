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
void far helper_9(void);
void far helper_10(void);
void far helper_11(void);
void far helper_12(void);
void far helper_13(void);
void far helper_14(void);
void far helper_15(void);
void far helper_16(void);
void far helper_17(void);
void far helper_18(void);
int far ovl_102050(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp L2A9
L12:
        jmp L5A7
L15:
        mov ax,mn6A06
        cmp ax,0x47
        jz short $+18
        jna short $+5
        jmp L5A7
L22:
        sub al,0x2
        jz short $+9
        sub al,0x36
        jz short $+71
        jmp L5A7
L2D:
        cmp word ptr mn6A04,0x92
        jz short $+13
        cmp word ptr mn6A04,0x90
        jz short $+5
        jmp L5A7
L40:
        mov ax,0x72
        push ax
        mov ax,0x73
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L5A7
L57:
        push word ptr mn6A04
        mov ax,0x73
        push ax
        mov ax,0x35
        push ax
        call far ptr helper_1
        add sp,0x6
        jmp L5A9
        nop
L6F:
        cmp word ptr mn6A04,0x8a
        jz short $+5
        jmp L189
L7A:
        mov ax,0x1
        push ax
        mov ax,0x99
        push ax
        push word ptr mn6A02
        call far ptr helper_2
        add sp,0x6
        or ax,ax
        jnz short $+39
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x45
LA7:
        mov dx,0xf009
        push dx
LAB:
        push ax
        call far ptr helper_4
        add sp,0x8
        jmp L2A3
LB7:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x248b
        mov dx,ds
        jmp short $+6
        nop
LD3:
        xor ax,ax
        cwd
LD6:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x46
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x10
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jnz short $+58
        mov ax,0xb
        push ax
        call far ptr helper_6
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_7
        add sp,0x2
        mov ax,0x5a03
        push ax
        mov ax,0x184
        push ax
        call far ptr helper_8
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
L15E:
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x6
        mov ax,0x1
        push ax
        mov ax,0x5
        push ax
        mov ax,0x8026
        push ax
        call far ptr helper_11
        add sp,0x6
        jmp L2A3
L189:
        cmp word ptr mn6A04,0x76
        jz short $+5
        jmp L26F
L193:
        mov ax,0x99
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+20
        mov ax,0x47
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        jmp short $+120
L1B9:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x48
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0xc
        mov ax,0x72
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+36
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x49
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x8
L223:
        mov ax,0x2e
        push ax
        call far ptr helper_6
        add sp,0x2
L22F:
        mov ax,0x8
        push ax
        call far ptr helper_12
        add sp,0x2
        xor ax,ax
        push ax
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_10
        add sp,0x6
        mov ax,0x75
        push ax
        call far ptr helper_13
        add sp,0x2
        cmp ax,0x117
        jnz short $+73
        mov ax,0x116
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_14
L269:
        add sp,0x4
        jmp short $+55
        nop
L26F:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x4a
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0xc
L2A3:
        mov ax,0x1
        jmp L5A9
L2A9:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L58F
L2B4:
        jna short $+5
        jmp L5A7
L2B9:
        cmp al,0x35
        jnz short $+5
        jmp L381
L2C0:
        ja short $+17
        sub al,0x8
        jz short $+37
        sub al,0xb
        jz short $+39
        sub al,0x19
        jz short $+29
        jmp L5A7
L2D1:
        sub al,0x38
        jnz short $+5
        jmp L5A7
L2D8:
        sub al,0x3
        jnz short $+5
        jmp L457
L2DF:
        sub al,0x9
        jnz short $+5
        jmp L457
L2E6:
        jmp L5A7
L2E9:
        mov ax,0x44
        jmp L3AF
L2EF:
        push word ptr mn6A04
        call far ptr helper_13
        add sp,0x2
        cmp ax,0x11a
        jnz short $+27
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x39
        jmp LA7
        nop
L319:
        mov ax,0x3a
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x99
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+54
        mov ax,0x3b
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x8a
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+18
        mov ax,0x3c
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
L371:
        mov ax,0x2e
        push ax
        call far ptr helper_6
        add sp,0x2
        jmp L2A3
        nop
L381:
        mov ax,0x1
        push ax
        mov ax,0x72
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x6
        or ax,ax
        jnz short $+5
        jmp L437
L39C:
        cmp word ptr mn6A02,0x92
        jz short $+27
        cmp word ptr mn6A02,0x90
        jz short $+19
        mov ax,0x41
L3AF:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        jmp L269
        nop
L3BD:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x40
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x8
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x6
        push word ptr mn6A04
        call far ptr helper_15
        add sp,0x2
        mov ax,0xa
        push ax
        mov ax,0x72
        push ax
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L2A3
L415:
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_16
        add sp,0x6
        mov ax,0xa
        push ax
        mov ax,0x72
        push ax
        call far ptr helper_9
        jmp L269
        nop
L437:
        mov ax,0x42
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x35
        push ax
        push word ptr mn6A04
        call far ptr helper_17
        jmp L269
L457:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_18
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3d
        jmp LA7
L483:
        mov ax,0x1
        push ax
        mov ax,0x99
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x6
        or ax,ax
        jnz short $+5
        jmp L533
L49E:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x246b
        push ds
        push ax
        call far ptr helper_4
        add sp,0x8
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x6
        mov ax,0x1
        push ax
        push word ptr mn6A04
        mov ax,0x8a
        push ax
        call far ptr helper_2
        add sp,0x6
        or ax,ax
        jz short $+52
        mov ax,0x8a
        push ax
        mov cx,0x2
        push cx
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x247b
        push ds
        push ax
        call far ptr helper_4
        add sp,0x8
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x8a
        push ax
        call far ptr helper_10
        add sp,0x6
L51A:
        mov ax,0x99
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x2482
        push ds
        jmp LAB
L533:
        mov ax,0x1
        push ax
        mov ax,0x72
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x6
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3e
        jmp LA7
L563:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $+50
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3f
        jmp LA7
L58F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x43
        jmp LA7
L5A7:
        xor ax,ax
L5A9:
    }
}
