extern int __near mn4DAE;
extern int __near mn63DC;
extern int __near mn63DE;

int far exe_95665(int a)
{
    _asm {
        sub sp,0xa
        sub ax,ax
        mov [bp-0x2],ax
        mov [bp-0x4],ax
        mov word ptr [bp-0x6],0x1
        cmp word ptr mn4DAE,0x1
        jng short $+83
        mov ax,mn63DC
        mov dx,mn63DE
        add ax,0xc
        mov [bp-0xa],ax
        mov [bp-0x8],dx
L27:
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        les bx, [bp-0xa]
        cmp es:[bx],ax
        jnz short $+8
        cmp es:[bx+0x2],dx
        jz short $+20
L3B:
        add word ptr [bp-0xa],0xc
        mov ax,mn4DAE
        inc word ptr [bp-0x6]
        cmp [bp-0x6],ax
        jl short $-33
        jmp short $+30
        nop
L4D:
        mov ax,[bp-0x6]
        mov cx,ax
        add ax,ax
        add ax,cx
        add ax,ax
        add ax,ax
        add ax,mn63DC
        mov dx,mn63DE
        mov [bp-0x4],ax
        mov [bp-0x2],dx
L68:
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
    }
}
