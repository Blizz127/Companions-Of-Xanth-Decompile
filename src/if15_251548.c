void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far if15_251548(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+29
        mov ax,0x126
        push ax
        mov ax,0x12e
        push ax
        call far ptr helper_0
        mov sp,bp
        cmp ax,0x1
        cmc
        sbb ax,ax
        and ax,0x125
        jmp LCE
L21:
        mov ax,0x126
        push ax
        mov ax,0x12e
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp LBF
L37:
        mov ax,0x126
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+99
        mov ax,0x4e
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x3476
        push ds
        push ax
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0x127
        push cx
        call far ptr helper_3
        mov sp,bp
        mov ax,0xa
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jnz short $+50
        mov ax,0xa
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_5
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_6
        jmp short $+15
LAB:
        mov ax,0x4f
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
LB8:
        mov sp,bp
LBA:
        mov ax,0x125
        jmp short $+17
LBF:
        mov ax,0x50
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        xor ax,ax
LCE:
    }
}
