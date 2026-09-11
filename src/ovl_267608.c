extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_267608(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA3
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
        mov ax,0x1e
L40:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+86
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+70
        ja short $+74
        cmp al,0x2c
        jz short $+52
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+36
        jmp short $+58
L6B:
        sub al,0x38
        jz short $+42
        sub al,0xc
        jz short $+38
        jmp short $+48
L75:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1c
        jmp short $-73
L8B:
        mov ax,0x19
        jmp short $-78
        nop
L91:
        mov ax,0x1b
        jmp short $-84
        nop
L97:
        mov ax,0x1a
        jmp short $-90
        nop
L9D:
        mov ax,0x1d
        jmp short $-96
        nop
LA3:
        xor ax,ax
LA5:
    }
}
