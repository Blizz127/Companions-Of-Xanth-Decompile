extern void __near ncFAF0(void);

int far exe_123772(void)
{
    _asm {
        pushf
        push ax
        xor ah,ah
        dec ax
        push cs
        call ncFAF0
        pop ax
        popf
        retf
    }
}
