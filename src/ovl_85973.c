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
void far helper_9(void);
void far helper_10(void);
void far helper_11(void);
int far ovl_85973(int a)
{
    _asm {
        sub sp,0xa
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp LF3
L12:
        jmp L41F
L15:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L41F
L20:
        mov ax,0xe
        push ax
        push word ptr mn6A02
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+57
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
        mov ax,0xc
L5B:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp LED
L6B:
        mov ax,mn6A04
        sub ax,0x4a
        jl short $+11
        jo short $+9
        dec ax
        jng short $+47
        dec ax
        dec ax
        jz short $+43
L7C:
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
        mov ax,0xe
        jmp short $-72
LA5:
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
        mov ax,0xd
        mov dx,0xf005
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
LED:
        mov ax,0x1
        jmp L421
LF3:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L2AD
LFE:
        jna short $+5
        jmp L41F
L103:
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+92
        sub al,0x19
        jz short $+12
        sub al,0x18
        jnz short $+5
        jmp L287
L116:
        jmp L41F
L119:
        cmp word ptr mn6A06,0x2c
        jnz short $+22
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+35
L134:
        cmp word ptr mn6A06,0x8
        jz short $+5
        jmp L41F
L13E:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L41F
L155:
        mov ax,0x229c
        push ds
        push ax
        call far ptr helper_4
        add sp,0x4
        jmp L41F
L165:
        mov ax,0xe
        push ax
        mov ax,0x49
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x223a
        jmp short $+6
        nop
L17F:
        mov ax,0x223f
L182:
        push ds
        push ax
        mov ax,0x6
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0xe
        push ax
        mov ax,0x49
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L277
L1AB:
        mov ax,0x7
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov word ptr [bp-0x4],0xffff
        mov word ptr [bp-0x6],0x0
        mov word ptr [bp-0x2],0x3
        mov word ptr [bp-0x8],0x223a
L1CF:
        mov ax,0x49
        push ax
        mov bx,[bp-0x8]
        push word ptr [bx]
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $+17
        cmp word ptr [bp-0x4],-1
        jnz short $+8
        mov ax,[bp-0x2]
        mov [bp-0x4],ax
L1F0:
        inc word ptr [bp-0x6]
L1F3:
        dec word ptr [bp-0x2]
        sub word ptr [bp-0x8],0x2
        cmp word ptr [bp-0x8],0x2234
        jnc short $-48
        cmp word ptr [bp-0x6],0x0
        jnz short $+18
        mov ax,0x2246
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $+99
        nop
L217:
        mov word ptr [bp-0x2],0x0
        mov word ptr [bp-0xa],0x2234
L221:
        mov ax,0x49
        push ax
        mov bx,[bp-0xa]
        push word ptr [bx]
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $+53
        cmp word ptr [bp-0xa],0x2234
        jna short $+29
        mov ax,[bp-0x2]
        cmp [bp-0x4],ax
        jnz short $+8
        mov ax,0x224f
        jmp short $+6
        nop
L24B:
        mov ax,0x2254
L24E:
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
L258:
        mov bx,[bp-0xa]
        push word ptr [bx]
        mov ax,0x83
        push ax
        call far ptr helper_1
        add sp,0x4
L269:
        inc word ptr [bp-0x2]
        add word ptr [bp-0xa],0x2
        cmp word ptr [bp-0xa],0x223a
        jc short $-84
L277:
        mov ax,0x2256
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp LED
L287:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x8
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp LED
        nop
L2AD:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2258
        jmp short $+6
        nop
L2C7:
        mov ax,0x225e
L2CA:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x2263
        jmp short $+5
L2F7:
        mov ax,0x2269
L2FA:
        push ds
        push ax
        mov ax,0x9
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
        mov ax,0xfa0
        push ax
        call far ptr helper_6
        add sp,0x2
        call far ptr helper_7
        mov ax,0xa
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x3e8
        push ax
        call far ptr helper_6
        add sp,0x2
        call far ptr helper_7
        mov ax,0x226e
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x7d0
        push ax
        call far ptr helper_6
        add sp,0x2
        call far ptr helper_7
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+23
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
        mov ax,0x2c
        jmp short $+21
L385:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        mov ax,0x8
L398:
        push ax
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x4
        mov ax,0x227d
        push ds
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x40
        push ax
        call far ptr helper_11
        add sp,0x2
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x2287
        jmp short $+5
L3D7:
        mov ax,0x228c
L3DA:
        push ds
        push ax
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x2293
        jmp short $+5
L3F5:
        mov ax,0x2297
L3F8:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
        jmp LED
L41F:
        xor ax,ax
L421:
    }
}
