extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_255995(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+91
        jmp LAB
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LAB
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+128
        push word ptr mn6A04
        mov ax,0x26
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
        mov ax,0xf
L53:
        mov dx,0xf042
        push dx
        push ax
        call far ptr helper_2
L5D:
        mov sp,bp
        mov ax,0x1
        jmp short $+75
        nop
L65:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+58
        ja short $+62
        sub al,0x12
        jz short $+12
        dec al
        jz short $+20
        sub al,0x19
        jz short $+22
        jmp short $+48
L7D:
        mov ax,0x3
        push ax
        call far ptr helper_3
        jmp short $-41
        nop
L89:
        mov ax,0xc
        jmp short $-57
        nop
L8F:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0xd
        jmp short $-80
LA5:
        mov ax,0xe
        jmp short $-85
        nop
LAB:
        xor ax,ax
LAD:
    }
}
