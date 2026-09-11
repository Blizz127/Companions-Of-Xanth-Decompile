extern int __near mn67B2;
extern int __near mn67B4;
extern int __near mn67B2;
extern int __near mn67B4;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_101290(int a)
{
    _asm {
        sub sp,0x8
        mov word ptr mn67B2,0xffff
        mov ax,0x1
        mov mn67B4,ax
        cmp [bp+0x6],ax
        jng short $+51
        mov ax,[bp+0x8]
        mov dx,[bp+0xa]
        add ax,0x4
        mov [bp-0x6],ax
        mov [bp-0x4],dx
        mov ax,[bp+0x6]
        dec ax
        mov [bp-0x8],ax
lbl2A:
        les bx, [bp-0x6]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        call far ptr helper_0
        add sp,0x4
        add word ptr [bp-0x6],0x4
        dec word ptr [bp-0x8]
        jnz short $-25
lbl45:
        cmp word ptr mn67B2,-1
        jnz short $+31
        mov ax,0x0
        mov cx,0x2ec4
        push cx
        push ax
        call far ptr helper_0
        add sp,0x4
        cmp word ptr mn67B2,-1
        jnz short $+8
        mov word ptr mn67B2,0x1
lbl69:
        call far ptr helper_1
        push word ptr mn67B2
        call far ptr helper_2
        add sp,0x2
        cmp word ptr mn67B4,0x0
        jz short $+7
        call far ptr helper_3
lbl86:
        call far ptr helper_4
        call far ptr helper_5
    }
}
