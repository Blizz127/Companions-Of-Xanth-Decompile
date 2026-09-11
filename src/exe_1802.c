extern int __near mn4039;
extern int __near mn403B;

int far exe_1802(int a)
{
    _asm {
        les bx, [bp+0x6]
        mov mn4039,bx
        mov word ptr mn403B,es
    }
}
