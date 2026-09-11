extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern char __near mb02F3;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_109575(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp L175
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L175
L1A:
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
        mov ax,0x12
L40:
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp L177
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L16F
L5E:
        jna short $+5
        jmp L175
L63:
        cmp al,0x2c
        jnz short $+5
        jmp L133
L6A:
        ja short $+13
        sub al,0x7
        jz short $+33
        sub al,0xc
        jz short $+55
        jmp L175
L77:
        sub al,0x2e
        jnz short $+5
        jmp L139
L7E:
        sub al,0xf
        jnz short $+5
        jmp L13F
L85:
        sub al,0x7
        jnz short $+5
        jmp L169
L8C:
        jmp L175
L8F:
        cmp byte ptr mb02F3,0x0
        jz short $+7
        xor ax,ax
        cwd
        jmp short $+8
L9B:
        mov ax,0x10
        mov dx,0xf00a
LA1:
        push dx
        push ax
        mov ax,0xf
        jmp short $-102
        nop
LA9:
        mov ax,0xa
        push ax
        mov ax,0x7d
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+71
        mov ax,0x5a03
        push ax
        mov ax,0x66
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0xa
        push ax
        mov ax,0x7d
        push ax
        call far ptr helper_4
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x9
        push ax
        mov ax,0x8026
        push ax
        call far ptr helper_5
        mov sp,bp
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        mov ax,0x8026
        push ax
        call far ptr helper_5
        jmp L4A
        nop
L101:
        mov ax,0x1
        push ax
        mov ax,0xbd
        push ax
        call far ptr helper_6
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x9
        jmp L40
        nop
L11B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp L40
        nop
L133:
        mov ax,0xb
        jmp L40
L139:
        mov ax,0xe
        jmp L40
L13F:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+9
        mov ax,0x11
        jmp L40
        nop
L159:
        mov ax,0x5a03
        push ax
        mov ax,0x12c
        push ax
        call far ptr helper_3
        jmp L4A
L169:
        mov ax,0xc
        jmp L40
L16F:
        mov ax,0xd
        jmp L40
L175:
        xor ax,ax
L177:
    }
}
