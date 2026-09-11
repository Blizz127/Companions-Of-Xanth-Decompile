extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_308099(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+117
        jmp L155
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L155
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+34
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x8
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        jmp short $+11
L4D:
        mov ax,0x54
        push ax
        call far ptr helper_3
L56:
        mov sp,bp
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x9
L6C:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
L76:
        mov sp,bp
        mov ax,0x1
        jmp L157
        nop
L7F:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L13D
L8A:
        jna short $+5
        jmp L155
L8F:
        cmp al,0x1a
        jnz short $+5
        jmp L117
L96:
        ja short $+15
        sub al,0x8
        jz short $+33
        sub al,0xb
        jz short $+69
        jmp L155
        nop
        nop
LA5:
        sub al,0x2c
        jz short $+20
        sub al,0xc
        jnz short $+5
        jmp L131
LB0:
        sub al,0xc
        jz short $+127
        jmp L155
        nop
        nop
        nop
        nop
LBB:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        cmp word ptr mn6A06,0x2c
        jnz short $+8
        mov ax,0x39aa
        jmp short $+6
        nop
LD9:
        mov ax,0x39af
LDC:
        push ds
        push ax
        mov ax,0x5
        jmp short $-117
LE3:
        mov ax,0x2
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        cmp word ptr mn0256,0x1ae
        jz short $+10
        cmp word ptr mn0256,0x1b1
        jnz short $+17
L102:
        mov ax,0x3
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
L111:
        mov ax,0x4
        jmp L6C
L117:
        cmp word ptr mn0256,0x1ae
        jnz short $+14
        mov ax,0x2
        push ax
        call far ptr helper_4
        jmp L76
L12B:
        mov ax,0x7
        jmp L6C
L131:
        push word ptr mn6A04
        call far ptr helper_5
        jmp L76
L13D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
        jmp L6C
L155:
        xor ax,ax
L157:
    }
}
