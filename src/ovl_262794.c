extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0350;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_262794(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LBD
L0F:
        jmp L117
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L117
L1E:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+36
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x2e
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp short $+102
L53:
        cmp byte ptr mb0350,0x0
        jz short $+43
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2f
        jmp short $+42
        nop
L83:
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
        mov ax,0x30
LAA:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
LB7:
        mov ax,0x1
        jmp short $+95
        nop
LBD:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+14
        sub ax,0x31
        jc short $+79
        sub ax,0x1
        jna short $+52
        jmp short $+72
LD1:
        mov ax,0x2b
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        cmp byte ptr mb0350,0x0
        jz short $+21
        mov ax,0x2c
LEB:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-65
        nop
LFB:
        mov ax,0x2d
        jmp short $-19
        nop
L101:
        xor ax,ax
        push ax
        mov ax,0x13f
        push ax
        push word ptr mn6A06
        call far ptr helper_3
        add sp,0x6
        jmp short $+5
        nop
L117:
        xor ax,ax
L119:
    }
}
