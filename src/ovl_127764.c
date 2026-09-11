extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
extern int __near mn02A6;
extern char __near mb2748;
extern char __near mb02F3;
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
int far ovl_127764(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+43
        jmp L303
L0F:
        mov ax,mn6A06
        sub ax,0x33
        jz short $+10
        sub ax,0x5
        jz short $+5
        jmp L303
L1F:
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0xd
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp L305
L35:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L2EF
L40:
        jna short $+5
        jmp L303
L45:
        cmp al,0x13
        jnz short $+5
        jmp L261
L4C:
        ja short $+13
        sub al,0x8
        jz short $+33
        sub al,0x5
        jz short $+51
        jmp L303
L59:
        sub al,0x2c
        jnz short $+5
        jmp L2CF
L60:
        sub al,0x13
        jnz short $+5
        jmp L2D5
L67:
        sub al,0x5
        jnz short $+5
        jmp L2E9
L6E:
        jmp L303
L71:
        mov ax,0xb
L74:
        mov dx,0xf017
        push dx
        push ax
        call far ptr helper_1
L7E:
        mov sp,bp
L80:
        mov ax,0x1
        jmp L305
        nop
L87:
        mov ax,mn0256
        sub ax,0x8c
        jz short $+14
        sub ax,0x8
        jz short $+9
        sub ax,0x3
        jz short $+10
        jmp short $-25
L9B:
        mov ax,0xf
        jmp short $-42
        nop
LA1:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x10
        jmp short $-67
LB9:
        cmp word ptr mn6A02,0x88
        jz short $+32
        cmp word ptr mn6A02,0x89
        jz short $+24
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        mov ax,0x11
        jmp short $+40
LDF:
        push word ptr mn6A02
        call far ptr helper_4
        add sp,0x2
        cmp ax,0x122
        jnz short $+39
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
L105:
        mov dx,0xf017
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L80
L115:
        push word ptr mn6A02
        call far ptr helper_4
        add sp,0x2
        cmp ax,0x146
        jnz short $+37
        mov ax,0x13
        mov dx,0xf017
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_5
        add sp,0x6
        jmp short $+36
        nop
L149:
        push word ptr mn6A02
        call far ptr helper_4
        add sp,0x2
        cmp ax,0x14a
        jnz short $+35
        mov ax,0x14
        mov dx,0xf017
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
L16A:
        mov ax,0x122
        push ax
        push word ptr mn6A02
        call far ptr helper_6
        jmp L7E
        nop
L17B:
        mov ax,0xa
        push ax
        push word ptr mn6A02
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L80
L192:
        mov ax,0x276c
        push ds
        push ax
        call far ptr helper_7
        add sp,0x4
        mov ax,0x15
        mov dx,0xf017
        push dx
        push ax
        call far ptr helper_8
        add sp,0x4
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x16
        mov dx,0xf017
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x122
        push ax
        push word ptr mn6A02
        call far ptr helper_6
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        inc word ptr mn02A6
        mov ax,0x1
        push ax
        push ax
        mov cx,0xf
        push cx
        call far ptr helper_10
        add sp,0x6
        call far ptr helper_11
        mov ax,0x1388
        push ax
        call far ptr helper_12
        add sp,0x2
        call far ptr helper_13
        mov ax,0x1
        push ax
        call far ptr helper_14
        add sp,0x2
        mov ax,0xd
        push ax
        push word ptr mn6A04
        call far ptr helper_15
        add sp,0x4
        mov ax,0x12
        push ax
        call far ptr helper_16
        add sp,0x2
        mov byte ptr mb2748,0x0
        mov ax,0x1
        push ax
        mov ax,0x11
        push ax
        call far ptr helper_17
        add sp,0x4
        mov byte ptr mb02F3,0x1
        jmp L80
L261:
        mov ax,mn0256
        sub ax,0x8c
        jz short $+16
        sub ax,0x8
        jz short $+31
        sub ax,0x3
        jz short $+60
        jmp L80
        nop
L277:
        cmp word ptr mn02A6,0x2
        jnl short $+9
        mov ax,0x3
        jmp L74
        nop
L285:
        mov ax,0x4
        jmp L74
L28B:
        cmp word ptr mn02A6,0x0
        jnz short $+9
        mov ax,0x5
        jmp L74
        nop
L299:
        cmp word ptr mn02A6,0x2
        jnl short $+9
        mov ax,0x6
        jmp L74
        nop
L2A7:
        mov ax,0x7
        jmp L74
L2AD:
        cmp word ptr mn02A6,0x2
        jnl short $+9
        mov ax,0x8
        jmp L74
        nop
L2BB:
        mov ax,0x9
L2BE:
        mov dx,0xf017
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L80
        nop
L2CF:
        mov ax,0xa
        jmp L74
L2D5:
        cmp word ptr mn02A6,0x2
        jnl short $+9
        mov ax,0x17
        jmp L74
        nop
L2E3:
        mov ax,0x18
        jmp short $-40
        nop
L2E9:
        mov ax,0xc
        jmp L74
L2EF:
        cmp word ptr mn02A6,0x2
        jnz short $+9
        mov ax,0xd
        jmp L74
        nop
L2FD:
        mov ax,0xe
        jmp short $-66
        nop
L303:
        xor ax,ax
L305:
    }
}
