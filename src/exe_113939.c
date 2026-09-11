
int far exe_113939(int a)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x2],0x0
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x20
        jnz short $+14
L11:
        inc word ptr [bp+0x6]
        mov bx,[bp+0x6]
        cmp byte ptr es:[bx],0x20
        jz short $-10
L1D:
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x30
        jl short $+17
        cmp byte ptr es:[bx],0x39
        jg short $+11
        mov al,es:[bx]
        cbw
        sub ax,0x30
        jmp short $+43
L35:
        cmp byte ptr es:[bx],0x41
        jl short $+18
        cmp byte ptr es:[bx],0x46
        jg short $+12
        mov al,es:[bx]
        cbw
        sub ax,0x37
        jmp short $+22
        nop
L4B:
        cmp byte ptr es:[bx],0x61
        jl short $+28
        cmp byte ptr es:[bx],0x66
        jg short $+22
        mov al,es:[bx]
        cbw
        sub ax,0x57
L5E:
        mov cl,0x4
        shl word ptr [bp-0x2],cl
        or [bp-0x2],ax
        inc word ptr [bp+0x6]
        jmp short $-76
L6B:
        mov ax,[bp-0x2]
    }
}
