extern int __near mn5A44;
void far helper_0(void);
int far exe_56142(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0x1f0
        jnz short $+31
        mov ax,0x1
        push ax
        mov ax,0x8b
        push ax
        call far ptr helper_0
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        and ax,0x1
        add ax,0x123e
        jmp short $+61
L27:
        mov word ptr [bp-0x2],0x0
        mov word ptr [bp-0x4],0x7f8
L31:
        mov ax,[bp+0x6]
        mov es, mn5A44
        mov bx,[bp-0x4]
        cmp es:[bx],ax
        jz short $+19
        inc word ptr [bp-0x2]
        add word ptr [bp-0x4],0x4
        cmp word ptr [bp-0x4],0x908
        jc short $-27
        jmp short $+17
        nop
L51:
        mov bx,[bp-0x2]
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x7fa]
        jmp short $+5
L5F:
        mov ax,0xffff
L62:
    }
}
