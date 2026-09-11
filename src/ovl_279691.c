extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb367C;
extern char __near mb0362;
extern int __near mn0256;
extern char __near mb0359;
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
int far ovl_279691(int a)
{
    _asm {
        sub sp,0x6
        mov word ptr [bp-0x2],0x0
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L143
L17:
        jmp L357
        nop
L1B:
        mov ax,mn6A06
        cmp ax,0x48
        jz short $+18
        jna short $+5
        jmp L357
L28:
        sub al,0x2
        jz short $+9
        sub al,0x36
        jz short $+5
        jmp L357
L33:
        mov ax,mn6A04
        sub ax,0x157
        jz short $+68
        sub ax,0x17
        jnz short $+5
        jmp LF3
L43:
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
        mov ax,0x35
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L77:
        mov ax,0x1
        jmp L359
L7D:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x33
        jmp L1B0
L97:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x34
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0x5
        push cx
        call far ptr helper_4
        add sp,0x6
        mov byte ptr mb367C,0x0
        call far ptr helper_5
        or ax,ax
        jz short $-114
        mov byte ptr mb0362,0x1
        jmp short $-121
        nop
LF3:
        mov ax,0x16c
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+24
        xor ax,ax
        push ax
        push word ptr mn6A04
        mov ax,0x4e
        push ax
        call far ptr helper_6
        add sp,0x6
        jmp L359
L11D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x32
        mov dx,0xf03e
L135:
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L77
        nop
L143:
        mov ax,mn6A06
        cmp ax,0x55
        jnz short $+5
        jmp L283
L14E:
        jna short $+5
        jmp L357
L153:
        cmp al,0x2c
        jnz short $+5
        jmp L26B
L15A:
        ja short $+13
        sub al,0x12
        jz short $+33
        dec al
        jz short $+101
        jmp L357
L167:
        sub al,0x38
        jnz short $+5
        jmp L271
L16E:
        sub al,0xc
        jnz short $+5
        jmp L271
L175:
        dec al
        jnz short $+5
        jmp L277
L17C:
        jmp L357
L17F:
        cmp word ptr mn0256,0x170
        jnz short $+8
        mov ax,0x2e
        jmp short $+38
        nop
L18D:
        cmp byte ptr mb0359,0x0
        jnz short $+7
        mov ax,0x2f
        jmp short $+25
L199:
        mov ax,0x16c
        push ax
        mov ax,0x16e
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+22
        mov ax,0x30
L1B0:
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L77
        nop
L1C1:
        mov ax,0x31
        jmp short $-20
        nop
L1C7:
        mov ax,0x20
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x157
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+34
        cmp byte ptr mb0359,0x0
        jz short $+11
        mov ax,0x22
        mov dx,0xf03e
        jmp short $+8
        nop
L1FB:
        mov ax,0x3696
        mov dx,ds
L200:
        push dx
        push ax
        mov ax,0x21
        mov dx,0xf03e
        push dx
        jmp short $+26
L20B:
        cmp byte ptr mb0359,0x0
        jz short $+7
        mov ax,0x23
        jmp short $+5
L217:
        mov ax,0x24
L21A:
        mov dx,0xf03e
        push dx
        push ax
        mov ax,0x36a6
        push ds
L223:
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x16c
        push ax
        mov ax,0x16e
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L77
L243:
        mov ax,0x16c
        push ax
        mov ax,0x16e
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x26
        jmp short $+6
        nop
L25D:
        mov ax,0x27
L260:
        mov dx,0xf03e
        push dx
        push ax
        mov ax,0x25
        jmp L135
L26B:
        mov ax,0x29
        jmp L1B0
L271:
        mov ax,0x28
        jmp L1B0
L277:
        push word ptr mn6A04
        call far ptr helper_7
        jmp short $+20
        nop
L283:
        cmp word ptr mn0256,0x170
        jnz short $+18
        mov ax,0x5
        push ax
        call far ptr helper_8
L294:
        add sp,0x2
        jmp L77
        nop
L29B:
        mov ax,0x2a
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x157
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+23
        mov ax,0x2b
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov word ptr [bp-0x2],0x1
L2D4:
        mov ax,0x16c
        push ax
        mov ax,0x16e
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+58
        cmp word ptr [bp-0x2],0x0
        jz short $+15
        mov ax,0x36b1
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
L2FB:
        mov ax,0x16c
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        inc word ptr [bp-0x2]
L320:
        cmp byte ptr mb0359,0x0
        jnz short $+37
        cmp word ptr [bp-0x2],0x0
        jz short $+15
        mov ax,0x36b6
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
L33A:
        mov ax,0x2d
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
L34A:
        mov ax,0x2e
        push ax
        call far ptr helper_9
        jmp L294
        nop
L357:
        xor ax,ax
L359:
    }
}
