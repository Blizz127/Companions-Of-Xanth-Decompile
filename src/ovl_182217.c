extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern char __near mb0332;
extern char __near mb0333;
extern int __near mn02C0;
extern char __near mb033C;
extern char __near mb0331;
extern int __near mn0058;
extern int __near mn0056;
extern char __near mb0326;
extern char __near mb0328;
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
int far ovl_182217(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp lbl199
lbl12:
        jmp lbl5C9
lbl15:
        mov ax,mn6A06
        sub ax,0x33
        jz short $+10
        sub ax,0x5
        jz short $+5
        jmp lbl5C9
lbl25:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+58
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x26
lbl60:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp lbl193
        nop
lbl71:
        cmp word ptr mn6A04,0x100
        jz short $+100
        cmp word ptr mn6A04,0x75
        jz short $+93
        cmp word ptr mn6A04,0xee
        jnz short $+43
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
        mov ax,0x29
        jmp short $-79
lblB1:
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
        jmp short $-120
        nop
lblDB:
        cmp word ptr mn6A04,0x100
        jnz short $+9
        cmp byte ptr mb0332,0x0
        jnz short $+16
lblEA:
        cmp word ptr mn6A04,0x75
        jnz short $+52
        cmp byte ptr mb0333,0x0
        jz short $+45
lblF8:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x27
        jmp lbl60
        nop
lbl123:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        cmp word ptr mn6A04,0x75
        jnz short $+7
        mov ax,0x2fda
        jmp short $+5
lbl141:
        mov ax,0x2fe0
lbl144:
        push ds
        push ax
        cmp word ptr mn6A04,0x75
        jnz short $+8
        mov ax,0x2fe6
        jmp short $+6
        nop
lbl153:
        mov ax,0x2feb
lbl156:
        push ds
        push ax
        mov ax,0x28
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
        cmp word ptr mn6A04,0x100
        jnz short $+9
        mov byte ptr mb0332,0x1
        jmp short $+7
lbl177:
        mov byte ptr mb0333,0x1
lbl17C:
        cmp word ptr mn6A04,0x75
        jnz short $+18
        xor ax,ax
        push ax
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_3
        add sp,0x6
lbl193:
        mov ax,0x1
        jmp lbl5CB
lbl199:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp lbl5C3
lbl1A4:
        jna short $+5
        jmp lbl5C9
lbl1A9:
        cmp al,0x2c
        jnz short $+5
        jmp lbl2E3
lbl1B0:
        ja short $+13
        sub al,0x8
        jz short $+27
        sub al,0xb
        jz short $+47
        jmp lbl5C9
lbl1BD:
        sub al,0x38
        jnz short $+5
        jmp lbl2FB
lbl1C4:
        sub al,0xc
        jnz short $+5
        jmp lbl319
lbl1CB:
        jmp lbl5C9
        nop
lbl1CF:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x23
        jmp lbl342
lbl1E7:
        mov ax,0x16
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0xd9
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+16
        sub ax,0xfe
        jz short $+97
        dec ax
        jnz short $+5
        jmp lbl2B9
lbl216:
        jmp lbl2D3
lbl219:
        cmp byte ptr mb0332,0x0
        jnz short $+17
        cmp byte ptr mb0333,0x0
        jnz short $+10
        mov ax,0x2fd2
        push ds
        jmp lbl2CA
        nop
lbl22F:
        cmp byte ptr mb0332,0x0
        jz short $+15
        mov ax,0x2fb0
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
lbl243:
        cmp byte ptr mb0333,0x0
        jnz short $+5
        jmp lbl2D3
lbl24D:
        cmp byte ptr mb0332,0x0
        jz short $+9
        mov ax,0x2fbf
        mov dx,ds
        jmp short $+5
lbl25B:
        xor ax,ax
        cwd
lbl25E:
        push dx
        push ax
        mov ax,0x2fc4
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $+102
lbl26F:
        mov ax,mn02C0
        or ax,ax
        jz short $+17
        dec ax
        jz short $+22
        dec ax
        jz short $+27
        dec ax
        jz short $+32
        dec ax
        jz short $+39
        jmp short $+47
        nop
lbl285:
        mov word ptr [bp-0x4],0x17
        jmp short $+34
        nop
lbl28D:
        mov word ptr [bp-0x4],0x18
        jmp short $+26
        nop
lbl295:
        mov word ptr [bp-0x4],0x19
        jmp short $+18
        nop
lbl29D:
        mov word ptr [bp-0x4],0x2fa0
        mov word ptr [bp-0x2],ds
        jmp short $+12
lbl2A7:
        mov word ptr [bp-0x4],0x1a
lbl2AC:
        mov word ptr [bp-0x2],0xf033
lbl2B1:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        jmp short $+20
lbl2B9:
        mov ax,0xff
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
lbl2CA:
        push ax
lbl2CB:
        call far ptr helper_2
        add sp,0x4
lbl2D3:
        mov ax,0x2e
        push ax
        call far ptr helper_5
lbl2DC:
        add sp,0x2
        jmp lbl193
        nop
lbl2E3:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        jmp short $+74
        nop
lbl2FB:
        cmp word ptr mn6A02,0xcd
        jz short $+5
        jmp lbl5C9
lbl306:
        mov ax,0x25
lbl309:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp lbl193
lbl319:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+40
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
lbl342:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp lbl193
        nop
lbl353:
        mov ax,0xcd
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+44
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov byte ptr mb033C,0x1
        jmp lbl5B7
lbl391:
        mov ax,0xfc
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp lbl5B7
lbl3A8:
        mov ax,0x1d
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1b58
        push ax
        call far ptr helper_6
        add sp,0x2
        mov ax,0x1a
        push ax
        call far ptr helper_7
        add sp,0x2
        mov ax,0xd9
        push ax
        call far ptr helper_8
        add sp,0x2
        cmp ax,0x155
        jz short $+5
        jmp lbl5A7
lbl3E4:
        mov ax,0x1e
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov cx,0xfe
        push cx
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0xd9
        push cx
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0xff
        push dx
        call far ptr helper_3
        add sp,0x6
        mov ax,0x1
        mov mb0331,al
        push ax
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_9
        add sp,0x6
        mov ax,0x1b58
        push ax
        call far ptr helper_6
        add sp,0x2
        mov ax,0x5a07
        push ax
        mov ax,0x220
        push ax
        call far ptr helper_10
        add sp,0x4
        mov ax,0x1f
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        cmp word ptr mn0058,0x0
        jnz short $+38
        cmp word ptr mn0056,0x1
        jz short $+31
        call far ptr helper_11
        mov al,0x1
        push ax
        mov ax,0x1b
        push ax
        mov ax,0xa6a
        push ax
        call far ptr helper_12
        add sp,0x6
        call far ptr helper_13
lbl492:
        xor ax,ax
        push ax
        push ax
        mov cx,0xe
        push cx
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0x100
        push cx
        call far ptr helper_3
        add sp,0x6
        mov ax,0x1c
        push ax
        call far ptr helper_7
        add sp,0x2
        mov byte ptr mb0326,0x1
        cmp word ptr mn0058,0x0
        jnz short $+38
        cmp word ptr mn0056,0x1
        jz short $+31
        call far ptr helper_11
        xor al,al
        push ax
        mov ax,0x1b
        push ax
        mov ax,0xa9b
        push ax
        call far ptr helper_12
        add sp,0x6
        call far ptr helper_13
lbl4EE:
        xor ax,ax
        push ax
        mov cx,0xfb
        push cx
        mov cx,0x10
        push cx
        call far ptr helper_3
        add sp,0x6
        mov ax,0xb
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0x20
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        push ax
        mov cx,0xa
        push cx
        call far ptr helper_9
        add sp,0x6
        mov ax,0x1388
        push ax
        call far ptr helper_6
        add sp,0x2
        mov ax,0x5a09
        push ax
        mov ax,0x223
        push ax
        call far ptr helper_10
        add sp,0x4
        mov ax,0x1
        push ax
        xor ax,ax
        push ax
        mov cx,0x3
        push cx
        call far ptr helper_9
        add sp,0x6
        mov byte ptr mb0328,0x1
        xor ax,ax
        push ax
        push ax
        mov cx,0x10
        push cx
        call far ptr helper_3
        add sp,0x6
        cmp word ptr mn0058,0x0
        jz short $+5
        jmp lbl193
lbl57C:
        cmp word ptr mn0056,0x1
        jnz short $+5
        jmp lbl193
lbl586:
        call far ptr helper_11
        mov al,0x1
        push ax
        mov ax,0x1b
        push ax
        mov ax,0xa9b
        push ax
        call far ptr helper_12
        add sp,0x6
        call far ptr helper_13
        jmp lbl193
        nop
lbl5A7:
        mov ax,0x21
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
lbl5B7:
        push word ptr mn6A04
        call far ptr helper_14
        jmp lbl2DC
lbl5C3:
        mov ax,0x24
        jmp lbl309
lbl5C9:
        xor ax,ax
lbl5CB:
    }
}
