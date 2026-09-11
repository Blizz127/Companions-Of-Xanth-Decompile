void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_136151(void)
{
    _asm {
        mov ax,0xb
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_1
        add sp,0x2
        call far ptr helper_2
        call far ptr helper_3
        mov ax,0x5a03
        push ax
        mov ax,0x16c
        push ax
        call far ptr helper_4
        add sp,0x4
        retf
    }
}
