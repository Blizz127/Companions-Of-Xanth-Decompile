
int far exe_14124(int a)
{
    _asm {
        push ds
        les di, [bp+0x6]
        lds si, [bp+0xa]
        mov bx,di
        mov cx,[bp+0xe]
        jcxz lbl1C
lbl10:
        lodsb
        or al,al
        jz short $+5
        stosb
        loop lbl10
lbl18:
        xor al,al
        rep stosb
lbl1C:
        mov ax,bx
        mov dx,es
        pop ds
    }
}
