void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far if15_199366(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+29
        mov ax,0x105
        push ax
        mov ax,0x90
        push ax
        call far ptr helper_0
        mov sp,bp
        cmp ax,0x1
        cmc
        sbb ax,ax
        and ax,0x107
        jmp L117
L21:
        mov ax,0x105
        push ax
        mov ax,0x90
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+23
        mov ax,0xd
        mov dx,0xf023
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        jmp L117
        nop
L49:
        mov ax,0xe
        mov dx,0xf023
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0xce
        push ax
        mov ax,0xee
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+53
        xor ax,ax
        push ax
        push ax
        mov ax,0xee
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0xce
        push ax
        call far ptr helper_4
        mov sp,bp
        cmp ax,0x166
        jnz short $+7
        mov ax,0x165
        jmp short $+5
L8F:
        mov ax,0x163
L92:
        push ax
        mov ax,0xce
        push ax
        call far ptr helper_5
        mov sp,bp
L9E:
        xor ax,ax
        push ax
        push ax
        mov cx,0xf2
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0xd9
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0xda
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0x104
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0x100
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0xfa
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0x58
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov ax,0x4d
        push ax
        call far ptr helper_3
        mov ax,0x107
L117:
    }
}
