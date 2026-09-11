extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_207057(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+125
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+116
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
L3D:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
L47:
        mov sp,bp
        mov ax,0x1
        jmp short $+63
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+46
        ja short $+50
        sub al,0x7
        jz short $+16
        dec al
        jz short $+18
        sub al,0xb
        jz short $+26
        sub al,0x19
        jz short $+10
        jmp short $+32
L6B:
        mov ax,0x3b
        jmp short $-49
        nop
L71:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-51
        nop
L7D:
        mov ax,0x39
        jmp short $-67
        nop
L83:
        mov ax,0x3a
        jmp short $-73
        nop
L89:
        xor ax,ax
L8B:
    }
}
