extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_267780(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp short $+125
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+116
        mov ax,0x23
L1A:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+98
        nop
        nop
L2D:
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
        jz short $+20
        jmp short $+68
L47:
        sub al,0x38
        jz short $+36
        sub al,0xc
        jz short $+32
        jmp short $+58
L51:
        mov ax,0x21
        jmp short $-58
        nop
L57:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x1f
        jmp short $-81
L6D:
        mov ax,0x20
        jmp short $-86
        nop
L73:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x22
        jmp short $-109
L89:
        xor ax,ax
L8B:
    }
}
