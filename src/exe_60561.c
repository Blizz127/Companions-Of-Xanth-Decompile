extern int __near mn0264;
void far helper_0(void);
int far exe_60561(int a)
{
    _asm {
        sub sp,0x8
        cmp word ptr [bp+0x6],0x0
        jz short $+88
        mov ax,[bp+0x6]
        add mn0264,ax
        cmp ax,0x1
        jng short $+10
        mov ax,0x7c2
        mov dx,ds
        jmp short $+6
        nop
L1D:
        xor ax,ax
        cwd
L20:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        cmp word ptr [bp+0xa],0x1
        sbb ax,ax
        and ax,0x15
        add ax,0xb
        push ax
        push dx
        push word ptr [bp-0x4]
        push word ptr [bp+0x6]
        cmp word ptr [bp+0x8],0x0
        jz short $+9
        mov ax,0x7c4
        mov dx,ds
        jmp short $+5
L47:
        xor ax,ax
        cwd
L4A:
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        push dx
        push ax
        mov ax,0x2
        mov dx,0xf007
        push dx
        push ax
        call far ptr helper_0
L5F:
    }
}
