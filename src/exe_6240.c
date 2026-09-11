extern void __near nc001E(void);

int far exe_6240(void)
{
    _asm {
        push ax
        call nc001E
        pop ax
        xor ah,ah
        mov sp,bp
        pop bp
        retf
    }
}
