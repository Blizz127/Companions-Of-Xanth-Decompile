void far helper_0(void);
int far exe_99939(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x0
        jnl short $+7
        mov word ptr [bp+0x6],0x0
L0B:
        cmp word ptr [bp+0x8],0x0
        jnl short $+7
        mov word ptr [bp+0x8],0x0
L16:
        cmp word ptr [bp+0x6],0x13f
        jng short $+7
        mov word ptr [bp+0x6],0x13f
L22:
        cmp word ptr [bp+0x8],0xc7
        jng short $+7
        mov word ptr [bp+0x8],0xc7
L2E:
        mov ax,0x4
        mov cx,[bp+0x6]
        shl cx,1
        mov dx,[bp+0x8]
        int 0x33
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
    }
}
