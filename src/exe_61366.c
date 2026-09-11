void far helper_0(void);
int far exe_61366(void)
{
    _asm {
        mov ax,0x9
        push ax
        mov ax,0x165
        push ax
        call far ptr helper_0
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        add ax,0x5a15
        retf
    }
}
