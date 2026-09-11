void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_305716(int a)
{
    _asm {
        mov ax,[bp+0x6]
        cmp ax,0xe
        jz short $+57
        ja short $+71
        sub al,0x8
        jz short $+13
        dec al
        jl short $+63
        sub al,0x2
        jng short $+37
        jmp short $+57
        nop
L19:
        mov ax,0xa
        push ax
        mov ax,0x1aa
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x9
L2B:
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp short $+24
L39:
        mov ax,0x8
        jmp short $-17
        nop
L3F:
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_2
L4F:
        xor ax,ax
    }
}
