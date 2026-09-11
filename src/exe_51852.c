void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_51852(int a)
{
    _asm {
        sub sp,0xa
        cmp word ptr [bp+0xa],0x0
        jng short $+78
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x6],ax
        mov [bp-0x4],dx
        mov ax,[bp+0xa]
        mov [bp-0x8],ax
L1B:
        push word ptr [bp-0x4]
        push word ptr [bp-0x6]
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+33
        les bx, [bp-0x6]
        mov ax,es:[bx+0x4]
        or ax,ax
        jz short $+11
        push ax
        call far ptr helper_1
        jmp short $+11
        nop
L41:
        push word ptr es:[bx]
        call far ptr helper_2
L49:
        add sp,0x2
L4C:
        add word ptr [bp-0x6],0xc
        dec word ptr [bp-0x8]
        jnz short $-56
L55:
    }
}
