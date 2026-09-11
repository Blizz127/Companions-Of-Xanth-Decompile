extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0354;
extern char __near mb0355;
extern char __near mb034E;
extern char __near mb33CE;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_248781(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L1DB
L0F:
        jmp L2B9
        nop
L13:
        mov ax,mn6A06
        dec ax
        dec ax
        jz short $+10
        sub ax,0x36
        jz short $+5
        jmp L2B9
L22:
        cmp word ptr mn6A04,0x12d
        jnz short $+21
        mov ax,0x1c
L2D:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp L1D4
        nop
L3D:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+43
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        jmp short $-73
        nop
L79:
        cmp word ptr mn6A04,0x138
        jz short $+5
        jmp L137
L84:
        mov ax,0x1e
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        cmp byte ptr mb0354,0x0
        jnz short $+25
        mov byte ptr mb0354,0x1
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_4
        mov sp,bp
LC4:
        mov ax,0xa
        push ax
        mov ax,0x129
        push ax
        call far ptr helper_5
        mov sp,bp
        or ax,ax
        jz short $+89
        mov ax,0xa
        push ax
        mov ax,0x12f
        push ax
        call far ptr helper_5
        mov sp,bp
        or ax,ax
        jnz short $+55
        mov ax,0x1f
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        cmp byte ptr mb0355,0x0
        jnz short $+25
        mov byte ptr mb0355,0x1
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x14
        push ax
        call far ptr helper_4
        mov sp,bp
L117:
        mov byte ptr mb034E,0x1
        jmp short $+18
        nop
L11F:
        mov ax,0x20
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
L12E:
        mov byte ptr mb33CE,0x0
        jmp L1D4
        nop
L137:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+57
        push word ptr mn6A02
        mov ax,0x12d
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x33fc
        jmp short $+6
        nop
L163:
        mov ax,0x3403
L166:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
        jmp L2D
        nop
L181:
        push word ptr mn6A02
        mov ax,0x22
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
        push word ptr mn6A02
        mov ax,0x12d
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x3409
        jmp short $+6
        nop
L1BF:
        mov ax,0x3412
L1C2:
        push ds
        push ax
        mov ax,0x22
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x10
L1D4:
        mov ax,0x1
        jmp L2BB
        nop
L1DB:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L291
L1E6:
        jna short $+5
        jmp L2B9
L1EB:
        sub al,0x10
        jz short $+14
        sub al,0x3
        jz short $+32
        sub al,0x19
        jz short $+118
        jmp L2B9
        nop
L1FB:
        xor ax,ax
        push ax
        mov ax,0x129
        push ax
        mov ax,0x4b
        push ax
        call far ptr helper_6
        add sp,0x6
        jmp L2BB
L211:
        push word ptr mn6A04
        mov ax,0x12d
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x15
        jmp short $+6
        nop
L22B:
        mov ax,0x16
L22E:
        mov dx,0xf026
        push dx
        push ax
        mov ax,0x14
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        push word ptr mn6A04
        mov ax,0x138
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L1D4
L257:
        mov ax,0x17
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp L1D4
        nop
L26B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
L280:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L1D4
        nop
L291:
        push word ptr mn6A04
        mov ax,0x12d
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x1a
        jmp short $+6
        nop
L2AB:
        mov ax,0x1b
L2AE:
        mov dx,0xf026
        push dx
        push ax
        mov ax,0x19
        jmp short $-54
        nop
L2B9:
        xor ax,ax
L2BB:
    }
}
