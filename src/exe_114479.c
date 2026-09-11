extern int __near mn51E0;
extern int __near mn51DE;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_114479(int a)
{
    _asm {
        sub sp,0x6
        cmp word ptr [bp+0x6],0x0
        jl short $+129
        cmp word ptr [bp+0x6],0x8
        jnl short $+123
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x2
        xor ax,ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x4
        mov ax,mn51E0
        mov [bp-0x4],ax
        mov ax,[bp+0x6]
        mov mn51E0,ax
        xor cx,cx
        push cx
        call far ptr helper_2
        add sp,0x2
        mov ax,mn51E0
        cmp [bp+0x6],ax
        jnz short $+10
        mov ax,0xffff
        jmp short $+8
        nop
        nop
        nop
L4F:
        mov ax,[bp-0x4]
L52:
        mov mn51E0,ax
        xor ax,ax
        mov bx,[bp+0x6]
        add bx,bx
        mov [bx+0x6860],ax
        mov mn51DE,ax
        mov [bp-0x2],ax
        mov word ptr [bp-0x6],0x6860
L6B:
        mov bx,[bp-0x6]
        cmp word ptr [bx],0x0
        jz short $+9
        mov ax,[bp-0x2]
        inc ax
        mov mn51DE,ax
L7A:
        inc word ptr [bp-0x2]
        add word ptr [bp-0x6],0x2
        cmp word ptr [bp-0x6],0x6870
        jc short $-27
L88:
    }
}
