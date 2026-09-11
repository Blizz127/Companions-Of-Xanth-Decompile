extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn02A8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_160418(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+37
        jmp LF1
L0F:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp LF1
L1A:
        mov ax,0x5a04
        push ax
        mov ax,0x307
L21:
        push ax
        call far ptr helper_0
L27:
        mov sp,bp
L29:
        mov ax,0x1
        jmp LF3
L2F:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LBB
L3A:
        jna short $+5
        jmp LF1
L3F:
        sub al,0x5
        jz short $+18
        sub al,0xe
        jz short $+56
        sub al,0x8
        jz short $+58
        sub al,0x4
        jz short $+60
        jmp LF1
        nop
L53:
        push word ptr mn0256
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x22
L70:
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_3
        jmp short $-83
        nop
L7D:
        mov ax,0x20
        jmp short $-16
        nop
L83:
        mov ax,0x23
        jmp short $-22
        nop
L89:
        mov ax,0x21
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x1770
        push ax
        call far ptr helper_4
        add sp,0x2
        mov word ptr mn02A8,0x1a
        mov ax,0x5a
        push ax
        call far ptr helper_5
        add sp,0x2
        jmp L29
        nop
LBB:
        mov ax,mn0256
        sub ax,0x5b
        jz short $+18
        sub ax,0x6c
        jz short $+23
        mov ax,0x5a04
        push ax
        mov ax,0x2e4
        jmp L21
        nop
LD3:
        mov ax,0x5a04
        push ax
        mov ax,0x2e5
        jmp L21
LDD:
        mov ax,0x5a04
        push ax
        mov ax,0x2fe
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp L29
        nop
LF1:
        xor ax,ax
LF3:
    }
}
