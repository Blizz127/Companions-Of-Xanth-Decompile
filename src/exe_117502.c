void far helper_0(void);
int far exe_117502(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        cmp [bp+0xa],ax
        jc short $+44
        les bx, [bp+0xa]
        mov al,es:[bx]
        mov [bp-0x4],al
        mov byte ptr es:[bx],0x0
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x2],ax
        mov al,[bp-0x4]
        les bx, [bp+0xa]
        mov es:[bx],al
        jmp short $+8
        nop
L35:
        mov word ptr [bp-0x2],0x0
L3A:
        mov ax,[bp-0x2]
    }
}
