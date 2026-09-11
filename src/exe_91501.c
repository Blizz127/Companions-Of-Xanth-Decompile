extern int __near mn4D38;
void far helper_0(void);
int far exe_91501(int a)
{
    _asm {
        cmp word ptr mn4D38,0x0
        jl short $+72
        xor ax,ax
        push ax
        call far ptr helper_0
        mov sp,bp
L11:
        cmp word ptr [bp+0x6],0x0
        jng short $+22
        inc word ptr mn4D38
        cmp word ptr mn4D38,0x8
        jnz short $+23
        mov word ptr mn4D38,0x0
        jmp short $+15
        nop
L2B:
        dec word ptr mn4D38
        jns short $+8
        mov word ptr mn4D38,0x7
L37:
        mov bx,mn4D38
        add bx,bx
        cmp word ptr [bx+0x6354],0x0
        jl short $-49
        mov ax,0x1
        push ax
        call far ptr helper_0
L4D:
    }
}
