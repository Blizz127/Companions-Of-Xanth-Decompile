extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
int far ovl_179107(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+93
        jmp LC3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC3
L1A:
        cmp word ptr mn6A04,0xee
        jnz short $+5
        jmp LC3
L25:
        cmp word ptr mn6A04,0xce
        jnz short $+5
        jmp LC3
L30:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x53
L56:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+96
L67:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+64
        ja short $+84
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+36
        jmp short $+68
L81:
        sub al,0x38
        jz short $+36
        sub al,0xc
        jz short $+32
        jmp short $+58
L8B:
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x51
        jmp short $-73
LA1:
        mov ax,0x4f
        jmp short $-78
        nop
LA7:
        mov ax,0x50
        jmp short $-84
        nop
LAD:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x52
        jmp short $-107
LC3:
        xor ax,ax
LC5:
    }
}
