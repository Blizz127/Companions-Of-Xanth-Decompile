
int far exe_20108(int a)
{
    _asm {
        push ds
        test byte ptr [bp+0xa],0x80
        jz short $+8
        mov ah,0x3c
        sub cx,cx
        jmp short $+7
L0D:
        mov ah,0x3d
        mov al,[bp+0xa]
L12:
        mov dx,[bp+0x8]
        mov ds,dx
        mov dx,[bp+0x6]
        int 0x21
        jnc short $+4
        sub ax,ax
L20:
        pop ds
    }
}
