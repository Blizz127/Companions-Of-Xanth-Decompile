void far helper(void);
void far exe_83832(void)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x4],0x630c
L08:
        push ds
        push word ptr [bp-0x4]
        call far ptr helper
        add sp,0x4
        add word ptr [bp-0x4],0x1a
        cmp word ptr [bp-0x4],0x6340
        jc short $+-21
    }
}
