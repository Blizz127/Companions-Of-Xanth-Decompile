extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern char __near mb0359;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_268778(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp L1C7
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L1C7
L1A:
        push word ptr mn6A02
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x41
L40:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
L4C:
        mov ax,0x1
        jmp L1C9
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1C1
L5E:
        jna short $+5
        jmp L1C7
L63:
        cmp al,0x13
        jz short $+120
        ja short $+14
        sub al,0x2
        jz short $+28
        sub al,0x6
        jz short $+104
        jmp L1C7
        nop
L75:
        sub al,0x2c
        jz short $+96
        sub al,0xc
        jz short $+12
        sub al,0xc
        jnz short $+5
        jmp L15F
L84:
        jmp L1C7
L87:
        cmp word ptr mn6A02,0x16d
        jnz short $+5
        jmp L1C7
L92:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_2
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        and ax,0x6
        add ax,0x69
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3e
        jmp L40
LD7:
        mov ax,0x3f
        jmp L40
LDD:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+47
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x359c
        push ds
        push ax
        call far ptr helper_1
        mov sp,bp
        cmp byte ptr mb0359,0x0
        jnz short $+5
        jmp L4C
L117:
        mov ax,0x38
        jmp L40
L11D:
        mov ax,0x14f
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+25
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x39
        jmp L40
L147:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3a
        jmp L40
        nop
L15F:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x3b
        jmp L40
        nop
L179:
        mov ax,0x16d
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x3c
        jmp L40
        nop
L193:
        mov ax,0x3d
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_5
        jmp L4A
        nop
L1C1:
        mov ax,0x40
        jmp L40
L1C7:
        xor ax,ax
L1C9:
    }
}
