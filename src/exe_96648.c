extern int __near mn63E4;
extern int __near mn63E6;

int far exe_96648(int a)
{
    _asm {
        sub sp,0x8
        mov word ptr [bp-0x4],0xffff
        mov word ptr [bp-0x2],0x0
        mov ax,mn63E4
        mov dx,mn63E6
        mov [bp-0x8],ax
        mov [bp-0x6],dx
L1A:
        les bx, [bp-0x8]
        mov ax,es:[bx+0x2]
        or ax,es:[bx]
        jz short $+19
        add word ptr [bp-0x8],0x4
        inc word ptr [bp-0x2]
        cmp word ptr [bp-0x2],0x100
        jl short $-24
        jmp short $+9
        nop
L37:
        mov ax,[bp-0x2]
        mov [bp-0x4],ax
L3D:
        mov ax,[bp-0x4]
    }
}
