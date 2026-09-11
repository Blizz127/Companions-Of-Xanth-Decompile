void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_305366(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x8
        jnl short $+5
        jmp LB1
L0B:
        jno short $+5
        jmp LB1
L10:
        sub ax,0x3
        jng short $+10
        sub ax,0x3
        jz short $+23
        jmp LB1
L1D:
        mov ax,0x2
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp LB1
L2F:
        mov ax,0x1388
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xb
        push ax
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x11b1
        push ax
        mov ax,0x3f5
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x7d0
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x1a9
        push ax
        call far ptr helper_5
        mov sp,bp
        mov ax,0x1
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x7d0
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x5
        push ax
        mov ax,0x1a8
        push ax
        call far ptr helper_6
        mov sp,bp
        mov ax,0x1aa
        push ax
        call far ptr helper_7
LB1:
        xor ax,ax
    }
}
