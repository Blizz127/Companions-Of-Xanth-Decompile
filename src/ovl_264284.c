void far helper_0(void);
void far helper_1(void);
int far ovl_264284(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+43
        push word ptr [bp+0x8]
        call far ptr helper_0
        mov sp,bp
        cbw
        push ax
        mov ax,0x3554
        push ds
        push ax
        mov ax,0x1396
        mov cx,0x3420
        push cx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1396
        mov dx,0x3420
        jmp short $+6
        nop
L2F:
        xor ax,ax
        cwd
L32:
    }
}
