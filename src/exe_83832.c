void far helper(void);
void far exe_83832(void)
{
    _asm {
        sub sp, 4
        mov word ptr [bp-4], 630Ch
        push ds
        push word ptr [bp-4]
        call far ptr helper
        add sp, 4
        add word ptr [bp-4], 1Ah
        cmp word ptr [bp-4], 6340h
        _emit 0x72
        _emit 0xE9
    }
}
