extern int __near mn13E6;
extern int __near mn13E0;

int far ovl_52325(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0x8000
        jc short $+81
        mov ax,mn13E6
        add byte ptr [bp+0x7],0x80
        cmp [bp+0x6],ax
        jnc short $+89
        mov ax,[bp+0x6]
        mov cx,ax
        add ax,ax
        add ax,cx
        add ax,ax
        add ax,0x31e0
        mov [bp-0x4],ax
        mov word ptr [bp-0x2],0x2ada
        cmp word ptr [bp+0x8],0x0
        jl short $+31
        les bx, [bp-0x4]
        sub ah,ah
        mov al,es:[bx]
        cmp ax,[bp+0x8]
        jng short $+18
        mov ax,es:[bx+0x2]
        add ax,[bp+0x8]
        add ax,0x15a4
        mov dx,0x2ada
        jmp short $+36
        nop
L4F:
        mov ax,cx
        add ax,0x3050
        mov dx,0x2ada
        jmp short $+25
L59:
        mov ax,mn13E0
        cmp [bp+0x6],ax
        jnc short $+14
        mov ax,[bp+0x6]
        add ax,0x168
        mov dx,0x2ada
        jmp short $+6
        nop
L6D:
        xor ax,ax
        cwd
L70:
    }
}
