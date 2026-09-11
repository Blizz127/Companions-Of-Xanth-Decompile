extern int __near mn0256;
extern char __near mb036E;
void far helper_0(void);
int far exe_64161(int a)
{
    _asm {
        sub sp,0x6
        mov ax,mn0256
        cmp ax,0x40
        jz short $+72
        ja short $+10
        sub al,0x22
        jz short $+66
        sub al,0x11
        jz short $+62
L15:
        mov word ptr [bp-0x2],0x0
        mov word ptr [bp-0x6],0x0
        mov word ptr [bp-0x4],0x2388
L24:
        mov ax,[bp+0x6]
        les bx, [bp-0x6]
        cmp es:[bx],ax
        jz short $+18
        add word ptr [bp-0x6],0x6
        inc word ptr [bp-0x2]
        cmp word ptr [bp-0x2],0x42
        jl short $-22
        jmp short $+48
        nop
L3F:
        mov al,es:[bx+0x5]
        cbw
        push ax
        mov al,es:[bx+0x4]
        cbw
        push ax
        push word ptr es:[bx+0x2]
        jmp short $+24
L51:
        mov ax,0x1
        push ax
        mov ax,0x7f
        push ax
        cmp byte ptr mb036E,0x1
        sbb ax,ax
        and ax,0x5
        add ax,0x302
        push ax
L67:
        call far ptr helper_0
L6C:
    }
}
