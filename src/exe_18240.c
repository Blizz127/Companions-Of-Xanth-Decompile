extern void __near nc00B9(void);

int far exe_18240(int a)
{
    _asm {
        push ds
        push bx
        lds bx, [bp+0x6]
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bx+0x2]
        push word ptr [bx]
        push cs
        call nc00B9
        mov [bx],ax
        mov [bx+0x2],dx
        pop bx
        pop ds
        pop bp
        retf 0x8
    }
}
