extern char __near mb0313;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_142469(void)
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
        mov ax,0x600
        push ax
        mov ax,0x329
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        mov mb0313,al
        retf
    }
}
