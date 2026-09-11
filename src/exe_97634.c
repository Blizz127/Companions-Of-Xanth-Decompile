void far helper_0(void);
void far helper_1(void);
int far exe_97634(int a)
{
    _asm {
        sub sp,0x6
        mov word ptr [bp-0x6],0xffff
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+48
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,ax
        jz short $+24
        les bx, [bp-0x4]
        test byte ptr es:[bx+0xa],0x80
        jnz short $+14
        push es
        push ax
        call far ptr helper_1
        mov word ptr [bp-0x6],0x0
L3E:
        mov ax,[bp-0x6]
    }
}
