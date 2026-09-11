extern int __near mn51E0;
void far helper_0(void);
int far exe_115042(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x0
        jnl short $+8
        mov ax,mn51E0
        mov [bp+0x6],ax
L0C:
        cmp word ptr [bp+0x6],0x0
        jl short $+42
        cmp word ptr [bp+0x6],0x8
        jnl short $+36
        mov ax,[bp+0x8]
        mov bx,[bp+0x6]
        add bx,bx
        mov [bx+0x68a0],ax
        mov cx,[bp+0xa]
        mov [bx+0x68b0],cx
        add cx,[bx+0x6850]
        push cx
        add ax,[bx+0x6880]
        push ax
        call far ptr helper_0
L3A:
    }
}
