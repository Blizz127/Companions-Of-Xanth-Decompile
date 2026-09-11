void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far exe_56851(void)
{
    _asm {
        call far ptr helper_0
        xor ax,ax
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x1f
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x100
        push ax
        call far ptr helper_3
        add sp,0x2
        call far ptr helper_4
        mov ax,0x4ba
        push ds
        push ax
        call far ptr helper_5
        add sp,0x4
        call far ptr helper_6
        call far ptr helper_7
        retf
    }
}
