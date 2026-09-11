extern int __near mn4F5A;
int g;
void far helper1(void);
void far helper2(void);
void far exe_104602(int a, int b, int c, int d)
{
    _asm {
        cmp word ptr mn4F5A,0x0
        jz short $+22
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper1
        jmp short $+20
        nop
L1B:
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper2
L2C:
    }
}
