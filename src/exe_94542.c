extern int __near mn4DB4;
int g;
void far helper(void);
int far exe_94542(int a, int b)
{
    _asm {
        sub sp,0x2
        cmp word ptr mn4DB4,0x10
        jl short $+7
        xor ax,ax
        jmp short $+28
        nop
L0F:
        mov ax,mn4DB4
        mov [bp-0x2],ax
        inc word ptr mn4DB4
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        push ax
        call far ptr helper
        mov ax,[bp-0x2]
L28:
    }
}
