extern int __near mn40ED;
extern char __near mb40EC;
void far helper_0(void);
int far exe_1835(int a)
{
    _asm {
        mov word ptr mn40ED,0x0
        inc byte ptr mb40EC
        mov ah,0x95
        call far ptr helper_0
        mov cx,0xffff
L14:
        cmp word ptr mn40ED,0x0
        jnz short $+4
        loop L14
L1D:
        cli
        mov word ptr mn40ED,0x0
        sti
    }
}
