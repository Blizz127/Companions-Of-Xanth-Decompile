extern int __near mn3FFE;
extern int __near mn4000;

int far exe_954(void)
{
    _asm {
        mov bx,mn3FFE
        mov [bx],al
        inc bx
        cmp bx,0x627c
        jc short $+5
        mov bx,0x5e7c
L10:
        mov mn3FFE,bx
        inc word ptr mn4000
        retf
    }
}
