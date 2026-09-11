void far helper_0(void);
int far exe_89173(int a)
{
    _asm {
        sub sp,0xa
        add word ptr [bp+0xa],0x4
        mov ax,[bp+0xa]
        mov [bp-0x4],ax
        mov ax,[bp+0xc]
        mov [bp-0x6],ax
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0xa],ax
        mov [bp-0x8],dx
L1F:
        push word ptr [bp-0x6]
        push word ptr [bp-0x4]
        les bx, [bp-0xa]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        call far ptr helper_0
        add sp,0x8
        mov ax,[bp+0xe]
        add word ptr [bp-0x4],0x1c
        cmp [bp-0x4],ax
        jng short $+20
        mov ax,[bp+0xa]
        mov [bp-0x4],ax
        mov ax,[bp+0x10]
        add word ptr [bp-0x6],0x16
        cmp [bp-0x6],ax
        jg short $+8
L55:
        add word ptr [bp-0xa],0x4
        jmp short $-58
L5B:
    }
}
