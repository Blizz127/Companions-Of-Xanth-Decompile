extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0329;
void far helper_0(void);
void far helper_1(void);
int far ovl_198090(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+101
        jmp LD1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LD1
L1A:
        cmp word ptr mn6A04,0xff
        jnz short $+5
        jmp LD1
L25:
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
        cmp byte ptr mb0329,0x0
        jz short $+8
        mov ax,0x3138
        jmp short $+6
        nop
L55:
        mov ax,0x313d
L58:
        push ds
        push ax
        mov ax,0xd
L5D:
        mov dx,0xf022
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+103
        nop
L6F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+86
        ja short $+90
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+58
        sub al,0x19
        jnz short $+78
L85:
        cmp byte ptr mb0329,0x0
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp short $-67
        nop
LA3:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xb
        jmp short $-90
LB9:
        cmp byte ptr mb0329,0x0
        jnz short $+7
        mov ax,0x8
        jmp short $-102
LC5:
        mov ax,0x9
        jmp short $-107
        nop
LCB:
        mov ax,0xc
        jmp short $-113
        nop
LD1:
        xor ax,ax
LD3:
    }
}
