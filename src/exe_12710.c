extern void __near ncEDA9(void);

int far exe_12710(int a)
{
    _asm {
        mov si,[bp+0x6]
        mov ax,[bp+0x8]
        mov di,ax
        cmp si,-1
        jz short $+22
        mov bx,ax
        test byte ptr [bx+0xa],0x1
        jnz short $+20
        test byte ptr [bx+0xa],0x80
        jz short $+8
        test byte ptr [bx+0xa],0x2
        jz short $+8
lbl23:
        mov ax,0xffff
        jmp short $+64
        nop
lbl29:
        mov ax,[di+0x8]
        or ax,[di+0x6]
        jnz short $+10
        push ds
        push di
        call ncEDA9
        add sp,0x4
lbl39:
        mov ax,[di]
        mov dx,[di+0x2]
        cmp [di+0x6],ax
        jnz short $+15
        cmp [di+0x8],dx
        jnz short $+10
        cmp word ptr [di+0x4],0x0
        jnz short $-41
        inc word ptr [di]
lbl50:
        inc word ptr [di+0x4]
        mov ax,si
        dec word ptr [di]
        les bx, [di]
        and byte ptr [di+0xa],0xef
        mov es:[bx],al
        or byte ptr [di+0xa],0x1
        sub ah,ah
lbl66:
    }
}
