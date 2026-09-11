void far helper_0(void);
void far helper_1(void);
int far exe_114367(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x0
        jl short $+53
        cmp word ptr [bp+0x6],0x8
        jnl short $+47
        mov ax,[bp+0x8]
        mov bx,[bp+0x6]
        add bx,bx
        mov [bx+0x6810],ax
        mov cx,[bp+0xa]
        mov [bx+0x6820],cx
        mov dx,[bp+0xc]
        mov [bx+0x6830],dx
        push ax
        call far ptr helper_0
        mov sp,bp
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_1
L39:
    }
}
