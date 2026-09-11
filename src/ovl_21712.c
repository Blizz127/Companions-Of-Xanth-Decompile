void far helper_0(void);
int far ovl_21712(int a)
{
    _asm {
        mov ax,0x41
        sub ax,[bp+0x8]
        mov cx,ax
        add ax,ax
        add ax,cx
        add ax,ax
        mov cx,0x5
        cwd
        idiv cx
        mov [bp+0x8],ax
        sub word ptr [bp+0x6],0xb7
        mov ax,[bp+0x6]
        cwd
        xor ax,dx
        sub ax,dx
        cmp ax,0x10
        jg short $+34
        mov ax,[bp+0x8]
        cwd
        xor ax,dx
        sub ax,dx
        cmp ax,0xa
        jg short $+21
        mov ax,[bp+0x6]
        cmp [bp+0x8],ax
        jg short $+7
        mov ax,0x8
        jmp short $+19
L43:
        mov ax,0x9
        jmp short $+14
        nop
L49:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
L54:
    }
}
