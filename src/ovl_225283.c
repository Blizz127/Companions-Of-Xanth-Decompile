extern int __near mn5AFA;
extern int __near mn5AF8;
extern int __near mn5AFC;
extern int __near mn5AFE;

int far ovl_225283(int a)
{
    _asm {
        mov ax,mn5AFA
        sub [bp+0x8],ax
        mov ax,mn5AF8
        sub [bp+0x6],ax
        mov ax,[bp+0x6]
        cwd
        idiv word ptr mn5AFC
        les bx, [bp+0xa]
        mov es:[bx],ax
        mov ax,[bp+0x8]
        cwd
        idiv word ptr mn5AFE
        add ax,ax
        les bx, [bp+0xe]
        mov es:[bx],ax
        mov ax,[bp+0x6]
        cwd
        idiv word ptr mn5AFC
        mov [bp+0x6],dx
        mov ax,[bp+0x8]
        cwd
        idiv word ptr mn5AFE
        mov [bp+0x8],dx
        cmp [bp+0x6],dx
        jg short $+20
        mov ax,mn5AFE
        sub ax,dx
        cmp ax,[bp+0x6]
        jl short $+10
L4F:
        les bx, [bp+0xe]
        inc word ptr es:[bx]
        jmp short $+56
L57:
        mov ax,mn5AFC
        sub ax,dx
        cmp ax,[bp+0x6]
        jnl short $+26
        mov ax,dx
        sub ax,mn5AFE
        add ax,mn5AFC
        cmp ax,[bp+0x6]
        jnl short $+11
        les bx, [bp+0xa]
        inc word ptr es:[bx]
        jmp short $-39
        nop
L79:
        mov ax,mn5AFE
        cwd
        sub ax,dx
        sar ax,1
        cmp ax,[bp+0x8]
        jnl short $+9
        les bx, [bp+0xe]
        add word ptr es:[bx],0x2
L8D:
    }
}
