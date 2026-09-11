extern int __near mn67B2;
extern int __near mn67B4;
void far helper_0(void);
int far exe_101226(int a)
{
    _asm {
        mov ax,0x4f6a
        push ds
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+11
        mov word ptr mn67B2,0x0
        jmp short $+31
        nop
L1F:
        mov ax,0x4f71
        push ds
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+8
        mov word ptr mn67B4,0x0
L3B:
    }
}
