
int far exe_19350(int a)
{
    _asm {
        les si, [bp+0x6]
        mov cx,es
        jcxz lbl0D
        or byte ptr es:[si-0x2],0x1
lbl0D:
    }
}
