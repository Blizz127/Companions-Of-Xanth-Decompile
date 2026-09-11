
int far exe_95822(int a)
{
    _asm {
        cmp word ptr [bp+0xe],0x0
        jz short $+48
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        cmp [bp+0xa],ax
        jnz short $+7
        cmp [bp+0xc],dx
        jz short $+32
lbl18:
        push ds
        push si
        push di
        mov cx,[bp+0xe]
        mov dx,[bp+0x10]
        lds si, [bp+0xa]
        les di, [bp+0x6]
lbl27:
        lodsb
        cmp al,dl
        jz short $+5
        mov es:[di],al
lbl2F:
        inc di
        dec cx
        jnz short $-10
        pop di
        pop si
        pop ds
lbl36:
    }
}
