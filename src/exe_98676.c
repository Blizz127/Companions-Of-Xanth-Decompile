extern int __near mn6428;
extern int __near mn4F24;
extern int __near mn642A;
extern int __near mn4F26;

int far exe_98676(int a)
{
    _asm {
        sub sp,0x4
        mov ax,mn6428
        sub ax,mn4F24
        mov [bp-0x2],ax
        mov cx,mn642A
        sub cx,mn4F26
        mov [bp-0x4],cx
        or ax,ax
        jg short $+9
        mov word ptr [bp-0x2],0x0
        jmp short $+12
L23:
        cmp ax,0x130
        jl short $+7
        mov word ptr [bp-0x2],0x130
L2D:
        cmp word ptr [bp-0x4],0x0
        jg short $+10
        mov word ptr [bp-0x4],0x0
        jmp short $+15
        nop
L3B:
        cmp word ptr [bp-0x4],0xb8
        jl short $+7
        mov word ptr [bp-0x4],0xb8
L47:
        mov ax,[bp-0x2]
        les bx, [bp+0x6]
        mov es:[bx],ax
        mov ax,[bp-0x4]
        les bx, [bp+0xa]
        mov sp,bp
        mov es:[bx],ax
    }
}
