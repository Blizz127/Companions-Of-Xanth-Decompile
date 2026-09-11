extern int __near mn4D38;
extern int __near mn4D3A;
extern int __near mn4DA0;
extern int __near mn4DA2;
extern int __near mn4DA4;

int far exe_91324(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0x0
        jl short $+94
        mov bx,[bp+0x6]
        add bx,bx
        mov word ptr [bx+0x6354],0xffff
        mov ax,mn4D38
        cmp [bp+0x6],ax
        jnz short $+8
        mov word ptr mn4D38,0xffff
L22:
        xor ax,ax
        mov mn4D3A,ax
        mov [bp-0x2],ax
        mov word ptr [bp-0x4],0x6354
L2F:
        mov bx,[bp-0x4]
        cmp word ptr [bx],-1
        jz short $+22
        mov ax,[bp-0x2]
        inc ax
        mov mn4D3A,ax
        cmp word ptr mn4D38,0x0
        jnl short $+8
        mov ax,[bp-0x2]
        mov mn4D38,ax
L4B:
        inc word ptr [bp-0x2]
        add word ptr [bp-0x4],0x2
        cmp word ptr [bp-0x4],0x6358
        jc short $-40
        mov ax,0xffff
        mov mn4DA0,ax
        mov mn4DA2,ax
        mov mn4DA4,ax
L65:
    }
}
