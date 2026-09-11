void far helper(void);
int far exe_83669(int a, char far *p, int n)
{
    _asm {
        sub sp,0x6
L03:
        dec word ptr [bp+0xc]
        js short $+41
        push word ptr [bp+0x6]
        call far ptr helper
        add sp,0x2
        mov [bp-0x2],ax
        inc ax
        jz short $+20
        mov al,[bp-0x2]
        les bx,word ptr [bp+0x8]
        inc word ptr [bp+0x8]
        mov es:[bx],al
        cmp al,0xa
        jnz short $+-36
        jmp short $+6
L2B:
        xor ax,ax
        jmp short $+5
L2F:
        mov ax,0x1
L32:
    }
}
