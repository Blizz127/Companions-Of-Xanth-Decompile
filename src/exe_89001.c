void far helper_0(void);
int far exe_89001(int a)
{
    _asm {
        sub sp,0xc
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        mov ax,0x140
        sub ax,[bp+0xa]
        mov [bp-0x2],ax
        jmp short $+47
        nop
L23:
        mov ax,[bp+0xa]
        mov [bp-0x4],ax
        jmp short $+22
L2B:
        mov al,[bp+0xe]
        les bx, [bp-0x8]
        cmp es:[bx],al
        jnz short $+8
        mov al,[bp+0x10]
        mov es:[bx],al
L3C:
        inc word ptr [bp-0x8]
L3F:
        mov ax,[bp-0x4]
        dec word ptr [bp-0x4]
        or ax,ax
        jg short $-28
        mov ax,[bp-0x2]
        add [bp-0x8],ax
L4F:
        mov ax,[bp+0xc]
        dec word ptr [bp+0xc]
        or ax,ax
        jg short $-52
    }
}
