extern int __near mn6A06;
extern char __near mb035E;
extern int __near mn0256;
extern int __near mn0798;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_178757(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LF7
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LE7
L16:
        jna short $+5
        jmp LF7
L1B:
        cmp al,0x27
        jz short $+68
        ja short $+14
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+58
        jmp LF7
        nop
L2D:
        sub al,0x2c
        jz short $+12
        sub al,0x18
        jnz short $+5
        jmp LCF
L38:
        jmp LF7
L3B:
        cmp word ptr mn6A06,0x8
        jnz short $+7
        mov ax,0x2f49
        jmp short $+5
L47:
        mov ax,0x2f4f
L4A:
        push ds
        push ax
        mov ax,0x4a
L4F:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_0
L59:
        mov sp,bp
        mov ax,0x1
        jmp LF9
L61:
        cmp byte ptr mb035E,0x0
        jz short $+7
        mov ax,0x47
        jmp short $-28
L6D:
        mov ax,0x48
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov byte ptr mb035E,0x1
        mov ax,0x8
        push ax
        call far ptr helper_2
        mov sp,bp
        push word ptr mn0256
        mov ax,0x5
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+35
        cmp word ptr mn0798,0x5
        jnz short $+28
        mov ax,0x7d0
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov ax,0x190
        push ax
        call far ptr helper_5
        mov sp,bp
LC0:
        xor ax,ax
        push ax
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_6
        jmp short $-116
LCF:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_7
        mov sp,bp
        push dx
        push ax
        mov ax,0x49
        jmp L4F
        nop
LE7:
        mov ax,0x5a12
        push ax
        mov ax,0x80b9
        push ax
        call far ptr helper_5
        jmp L59
LF7:
        xor ax,ax
LF9:
    }
}
