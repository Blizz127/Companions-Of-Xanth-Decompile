extern int __near mn0290;
void far helper_0(void);
void far helper_1(void);
int far exe_61201(int a)
{
    _asm {
        sub sp,0x8
        mov ax,0x5
        sub ax,[bp+0x6]
        mov cx,ax
        imul cx
        mov cx,ax
        mov ax,0x1
        sub ax,[bp+0x8]
        mov bx,ax
        imul bx
        add ax,cx
        mov [bp-0x6],ax
        mov ax,0xcd
        push ax
        mov ax,0xf2
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+73
        mov ax,0xa
        push ax
        mov ax,0xf2
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+53
        cmp word ptr mn0290,0x5
        jz short $+46
        mov word ptr [bp-0x8],0x0
L52:
        mov ax,[bp-0x8]
        mov cx,ax
        imul cx
        cmp ax,[bp-0x6]
        jg short $+14
        mov ax,cx
        inc ax
        mov cx,ax
        imul cx
        cmp ax,[bp-0x6]
        jg short $+11
L6A:
        inc word ptr [bp-0x8]
        cmp word ptr [bp-0x8],0xc
        jl short $-31
L73:
        mov ax,[bp-0x8]
        jmp short $+5
        nop
L79:
        xor ax,ax
L7B:
    }
}
