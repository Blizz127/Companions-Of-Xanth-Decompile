extern int __near mn000C;
void far helper_0(void);
int far exe_468(void)
{
    _asm {
        xor ax,ax
        call far ptr helper_0
        push ds
        mov ah,0x25
        mov al,0x8
        lds dx, cs:mn000C
        int 0x21
        pop ds
        retf
    }
}
