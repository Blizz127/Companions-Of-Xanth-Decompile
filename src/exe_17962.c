extern int __near mn59F6;
void far helper_0(void);
int far exe_17962(int a)
{
    _asm {
        sub sp,0x2
        cmp word ptr [bp+0x6],0x0
        jl short $+10
        mov ax,mn59F6
        cmp [bp+0x6],ax
        jl short $+8
L11:
        mov ax,mn59F6
        jmp short $+6
        nop
L17:
        mov ax,[bp+0x6]
L1A:
        mov [bp-0x2],ax
        mov bx,ax
        add bx,ax
        add bx,bx
        push word ptr [bx+0x5960]
        push word ptr [bx+0x595e]
        mov ax,0x69bc
        push ds
        push ax
        call far ptr helper_0
        mov ax,0x69bc
        mov dx,ds
    }
}
