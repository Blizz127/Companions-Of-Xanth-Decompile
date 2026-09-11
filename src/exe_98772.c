extern int __near mn4F24;
extern int __near mn4F26;
extern int __near mn4F20;
extern int __near mn4F22;

int far exe_98772(int a)
{
    _asm {
        sub sp,0x2a
        mov ax,[bp+0xe]
        sub ax,[bp+0xa]
        sub ax,mn4F24
        mov [bp-0x1c],ax
        mov ax,[bp+0x10]
        sub ax,[bp+0xc]
        sub ax,mn4F26
        mov [bp-0x1a],ax
        or ax,ax
        jnl short $+14
        neg ax
        mov [bp-0x1e],ax
        mov word ptr [bp-0x1a],0x0
        jmp short $+7
L2D:
        mov word ptr [bp-0x1e],0x0
L32:
        mov ax,0x10
        sub ax,[bp-0x1a]
        mov [bp-0x20],ax
        mov word ptr [bp-0x8],0x8000
        mov word ptr [bp-0xa],0x1
        cmp word ptr [bp-0x1c],0x0
        jnl short $+22
        mov cl,[bp-0x1c]
        neg cl
        mov ax,0x8000
        shr ax,cl
        mov [bp-0x8],ax
        mov word ptr [bp-0x1c],0x0
        jmp short $+19
L5F:
        cmp word ptr [bp-0x1c],0x0
        jng short $+13
        mov cl,[bp-0x1c]
        mov ax,0x1
        shl ax,cl
        mov [bp-0xa],ax
L70:
        mov cl,0x4
        mov ax,[bp-0x1a]
        shl ax,cl
        add ax,[bp-0x1c]
        add [bp+0x6],ax
        mov ax,mn4F20
        mov dx,mn4F22
        mov [bp-0xe],ax
        add ax,0x20
        mov [bp-0x12],ax
        mov ax,[bp-0x1e]
        mov [bp-0x18],ax
        cmp ax,[bp-0x20]
        jl short $+5
        jmp L120
L9B:
        add ax,ax
        mov cx,ax
        add ax,[bp-0x12]
        mov [bp-0x24],ax
        mov [bp-0x22],dx
        add cx,[bp-0xe]
        mov [bp-0x28],cx
        mov [bp-0x26],dx
        mov ax,[bp-0x20]
        sub ax,[bp-0x18]
        mov [bp-0x2a],ax
LBA:
        les bx, [bp-0x28]
        mov ax,es:[bx]
        mov [bp-0x4],ax
        les bx, [bp-0x24]
        mov ax,es:[bx]
        mov [bp-0x6],ax
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x16],ax
        mov [bp-0x14],dx
        mov ax,[bp-0x8]
        mov [bp-0x2],ax
        cmp ax,[bp-0xa]
        jc short $+46
LE3:
        mov ax,[bp-0x2]
        test [bp-0x6],ax
        jz short $+12
        les bx, [bp-0x16]
        mov byte ptr es:[bx],0xf
        jmp short $+15
        nop
LF5:
        test [bp-0x4],ax
        jnz short $+9
        les bx, [bp-0x16]
        mov byte ptr es:[bx],0x0
L101:
        inc word ptr [bp-0x16]
        mov ax,[bp-0xa]
        shr word ptr [bp-0x2],1
        cmp [bp-0x2],ax
        jnc short $-42
L10F:
        add word ptr [bp+0x6],0x10
        add word ptr [bp-0x24],0x2
        add word ptr [bp-0x28],0x2
        dec word ptr [bp-0x2a]
        jnz short $-100
L120:
    }
}
