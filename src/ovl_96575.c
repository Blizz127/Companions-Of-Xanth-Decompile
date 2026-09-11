extern char __near mb030A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_96575(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x8
        jz short $+25
        dec ax
        jnl short $+5
        jmp LA2
L0E:
        jno short $+5
        jmp LA2
L13:
        dec ax
        dec ax
        jng short $+42
        dec ax
        dec ax
        jz short $+68
        jmp LA2
        nop
L1F:
        mov ax,0xa
        push ax
        mov ax,0x63
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1f
L31:
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp short $+101
L3F:
        mov ax,0x5
        push ax
        mov ax,0x63
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+7
        mov ax,0x1d
        jmp short $-36
L57:
        mov ax,0x1e
        jmp short $-41
        nop
L5D:
        cmp byte ptr mb030A,0x0
        jnz short $+64
        mov ax,0x6
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov ax,0x114
        push ax
        call far ptr helper_4
        mov sp,bp
        mov byte ptr mb030A,0x1
        xor ax,ax
        push ax
        push ax
        mov cx,0x9
        push cx
        call far ptr helper_5
        mov sp,bp
        mov ax,0x1
        push ax
        xor ax,ax
        push ax
        mov ax,0x8026
        push ax
        call far ptr helper_6
LA2:
        xor ax,ax
    }
}
