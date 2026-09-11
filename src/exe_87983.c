extern int __near mn6DFE;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_87983(int a)
{
    _asm {
        push word ptr [bp+0x8]
        mov ax,[bp+0xa]
        add ax,[bp+0x6]
        push ax
        push word ptr [bp+0xc]
        push word ptr [bp+0xe]
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0xa]
        push ax
        call far ptr helper_0
        xor ax,ax
        push ax
        mov cx,mn6DFE
        cmp cx,ax
        jnl short $+4
        mov cx,ax
L2C:
        push cx
        push ax
        call far ptr helper_1
        push word ptr [bp+0x8]
        mov ax,[bp+0xe]
        sub ax,[bp+0x6]
        push ax
        push word ptr [bp+0xc]
        push word ptr [bp+0xe]
        mov ax,0x2
        push ax
        call far ptr helper_2
    }
}
