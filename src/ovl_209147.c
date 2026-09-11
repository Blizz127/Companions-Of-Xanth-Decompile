extern int __near mn31FC;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_209147(int a)
{
    _asm {
        cmp word ptr [bp+0xe],0x0
        jz short $+39
        push word ptr mn31FC
        call far ptr helper_0
        mov sp,bp
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp short $+20
        nop
L2B:
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_2
L3C:
    }
}
