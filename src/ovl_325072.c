void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_325072(int a)
{
    _asm {
        mov ax,[bp+0x6]
        cmp ax,0xe
        jz short $+111
        jna short $+5
        jmp L8D
L0D:
        sub al,0x8
        jz short $+8
        sub al,0x5
        jz short $+34
        jmp short $+120
L17:
        mov ax,0x1
        mov dx,0xf04d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x2
        mov dx,0xf04d
        push dx
        push ax
        call far ptr helper_0
        jmp short $+90
L35:
        mov ax,0x29
        push ax
        call far ptr helper_1
        add sp,0x2
        xor ax,ax
        push ax
        mov ax,0x2b
        push ax
        call far ptr helper_2
        add sp,0x4
        call far ptr helper_3
        mov ax,0x1
        push ax
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_4
        add sp,0x6
        mov ax,0x1388
        push ax
        call far ptr helper_5
        add sp,0x2
        jmp short $+27
        nop
L75:
        mov ax,0xbb8
        push ax
        call far ptr helper_5
        add sp,0x2
        xor ax,ax
        mov dx,0xf04d
        push dx
        push ax
        call far ptr helper_6
L8D:
        xor ax,ax
    }
}
