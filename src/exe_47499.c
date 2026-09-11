void far helper_0(void);
void far helper_1(void);
int far exe_47499(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0xc]
        mul word ptr [bp+0xa]
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        push word ptr [bp+0xe]
        call far ptr helper_0
        add sp,0x8
        sub dx,dx
        div word ptr [bp+0xa]
        mov [bp-0x2],ax
        or ax,ax
        jnz short $+15
        mov ax,0x900
        mov cx,0x21aa
        push cx
        push ax
        call far ptr helper_1
L34:
        mov ax,[bp-0x2]
    }
}
