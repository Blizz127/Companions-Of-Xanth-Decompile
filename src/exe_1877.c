extern char __near mb40EC;
void far helper_0(void);
int far exe_1877(void)
{
    _asm {
        mov ah,0x94
        call far ptr helper_0
        dec byte ptr mb40EC
        retf
    }
}
