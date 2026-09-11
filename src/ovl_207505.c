extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_207505(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LAD
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LAD
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
        mov ax,0x48
L40:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+96
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+80
        ja short $+84
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+36
        jmp short $+68
L6B:
        sub al,0x38
        jz short $+36
        sub al,0xc
        jz short $+32
        jmp short $+58
L75:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x15
        jmp short $-73
L8B:
        mov ax,0x45
        jmp short $-78
        nop
L91:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x46
        jmp short $-101
LA7:
        mov ax,0x47
        jmp short $-106
        nop
LAD:
        xor ax,ax
LAF:
    }
}
