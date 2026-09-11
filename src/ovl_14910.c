void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_14910(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x12]
        cmp ax,0xb
        jz short $+126
        ja short $+14
        sub al,0x2
        jz short $+16
        dec al
        jz short $+116
        sub al,0x7
        jz short $+8
L19:
        xor ax,ax
        jmp LD7
        nop
L1F:
        cmp word ptr [bp+0x12],0x2
        jnz short $+28
        push word ptr [bp+0x10]
        push word ptr [bp+0xe]
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        jmp short $+26
        nop
L3F:
        push word ptr [bp+0x10]
        push word ptr [bp+0xe]
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_1
L56:
        add sp,0xc
        mov [bp-0x8],ax
        mov ax,[bp+0xc]
        cmp [bp-0x8],ax
        jnl short $+32
        les bx, [bp+0xe]
        test byte ptr es:[bx+0xa],0x20
        jz short $+22
        mov ax,0x1
        push ax
        mov ax,0x0
        mov cx,0x3153
        push cx
        push ax
        call far ptr helper_2
        add sp,0x6
L82:
        mov ax,[bp-0x8]
        jmp short $+82
L87:
        mov ax,[bp+0xe]
        mov dx,[bp+0x10]
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov ax,[bp+0xc]
        mul word ptr [bp+0xa]
        mov [bp-0x6],ax
        cmp word ptr [bp+0x12],0x3
        jnz short $+21
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        les bx, [bp-0x4]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        jmp short $+19
LB5:
        push ax
        les bx, [bp-0x4]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
LC6:
        call far ptr helper_3
        mov ax,[bp-0x6]
        les bx, [bp-0x4]
        add es:[bx],ax
        mov ax,[bp+0xc]
LD7:
    }
}
