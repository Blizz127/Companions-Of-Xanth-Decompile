extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb2042;
extern char __near mb0322;
extern char __near mb2043;
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
int far ovl_81551(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L199
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L193
L16:
        jna short $+5
        jmp L199
L1B:
        sub al,0x8
        jz short $+26
        sub al,0xb
        jnz short $+5
        jmp LBB
L26:
        sub al,0x19
        jnz short $+5
        jmp LF1
L2D:
        sub al,0x18
        jnz short $+5
        jmp L18D
L34:
        jmp L199
L37:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+37
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x12
L5E:
        mov dx,0xf004
        push dx
L62:
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp short $+75
        nop
L6D:
        mov ax,0x13
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        mov ax,0x21f0
        push ds
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        mov sp,bp
        call far ptr helper_6
        call far ptr helper_7
        mov byte ptr mb2042,0x0
LB5:
        mov ax,0x1
        jmp L19B
LBB:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x21ce
        jmp short $+5
LD3:
        mov ax,0x21d3
LD6:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x21da
        push ds
        jmp L62
LF1:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+25
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x10
        jmp L5E
L11B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x11
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        mov sp,bp
        mov ax,0x21e4
        push ds
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        mov sp,bp
        cmp byte ptr mb0322,0x0
        jnz short $+5
        jmp LB5
L16F:
        mov ax,0x3e
        push ax
        mov ax,0x50
        push ax
        call far ptr helper_9
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp LB5
L185:
        mov byte ptr mb2043,0x1
        jmp LB5
L18D:
        mov ax,0x14
        jmp L5E
L193:
        mov ax,0x15
        jmp L5E
L199:
        xor ax,ax
L19B:
    }
}
