
int far exe_95782(int a)
{
    _asm {
        cmp word ptr [bp+0xe],0x0
        jz short $+25
        push ds
        push si
        push di
        mov cx,[bp+0xe]
        lds si, [bp+0xa]
        les di, [bp+0x6]
lbl14:
        lodsb
        xor es:[di],al
        inc di
        dec cx
        jnz short $-6
        pop di
        pop si
        pop ds
lbl1F:
    }
}
