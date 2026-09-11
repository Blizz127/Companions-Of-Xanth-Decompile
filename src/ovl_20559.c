void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_20559(int a)
{
    _asm {
        sub sp,0x2
        call far ptr helper_0
        call far ptr helper_1
        or ax,ax
        jnz short $+26
        mov word ptr [bp-0x2],0xffff
        mov ax,0x191
        mov cx,0x3181
        push cx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $+17
        nop
L29:
        push word ptr [bp+0x6]
        call far ptr helper_3
        add sp,0x2
        mov [bp-0x2],ax
L37:
        call far ptr helper_4
        call far ptr helper_5
        mov ax,[bp-0x2]
    }
}
