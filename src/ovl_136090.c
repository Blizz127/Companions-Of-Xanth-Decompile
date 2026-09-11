extern char __near mb0308;
void far helper_0(void);
void far helper_1(void);
int far ovl_136090(void)
{
    _asm {
        mov ax,0x1
        mov mb0308,al
        push ax
        mov ax,0x9b
        push ax
        mov ax,0x8a
        push ax
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x98
        push cx
        mov cx,0x73
        push cx
        call far ptr helper_0
        add sp,0x6
        mov ax,0xa
        push ax
        mov ax,0x73
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        retf
    }
}
