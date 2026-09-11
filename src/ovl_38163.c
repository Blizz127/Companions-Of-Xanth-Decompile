void far helper_0(void);
int far ovl_38163(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+10
        dec ax
        jz short $+29
        dec ax
        jz short $+48
        jmp short $+78
L0F:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        jmp short $+47
L25:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        jmp short $+21
L3B:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
L4E:
        push ax
        mov ax,0x2
L52:
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_0
L5B:
    }
}
