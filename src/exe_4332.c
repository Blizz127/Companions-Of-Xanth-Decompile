extern char __near mb4227;
extern int __near mn422C;
extern int __near mn4223;

int far exe_4332(void)
{
    _asm {
        iret
        mov cx,0xffff
        cmp byte ptr mb4227,0x0
        jnz short $+10
        inc byte ptr mb4227
        mov cx,mn422C
L13:
        sub cx,mn4223
    }
}
