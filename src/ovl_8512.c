void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_8512(int a)
{
    _asm {
        sub sp,0x4
        xor ax,ax
        push ax
        mov cx,0x1767
        push ds
        push cx
        call far ptr helper_0
        add sp,0x6
        mov [bp-0x4],ax
        or ax,ax
        jnz short $+23
        mov ax,0x0
        mov cx,0x311f
        push cx
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
L2F:
        push word ptr [bp-0x4]
        mov ax,0x1
        push ax
        mov cx,0x2
        push cx
        lea cx,[bp-0x2]
        push ss
        push cx
        call far ptr helper_3
        add sp,0xa
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        mov ax,0x1
        push ax
        mov ax,0x72
        mov cx,0x3420
        push cx
        push ax
        call far ptr helper_3
        add sp,0xa
        push word ptr [bp-0x4]
        call far ptr helper_4
    }
}
