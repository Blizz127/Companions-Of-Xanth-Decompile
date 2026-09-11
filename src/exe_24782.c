extern int __near mn4D34;

int far exe_24782(void)
{
    _asm {
        mov al,0x0
        iret
        push ax
        push ds
        mov ax,0x38af
        mov ds,ax
        inc word ptr mn4D34
        pop ds
        pop ax
        iret
    }
}
