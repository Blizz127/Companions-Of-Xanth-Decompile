extern int __near mn6808;
extern int __near mn6806;
extern int __near mn680A;
extern int __near mn680C;
extern int __near mn680E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_111047(int a)
{
    _asm {
        sub sp,0x6
        lea ax,[bp-0x6]
        push ss
        push ax
        lea ax,[bp-0x4]
        push ss
        push ax
        lea ax,[bp-0x2]
        push ss
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x10
        xor ax,ax
        push ax
        mov cx,0x6
        push cx
        mov cx,[bp+0x8]
        add cx,mn6808
        dec cx
        push cx
        mov cx,[bp+0x6]
        add cx,mn6806
        dec cx
        push cx
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        mov cx,[bp-0x2]
        mov mn680A,cx
        push cx
        call far ptr helper_1
        add sp,0xe
        mov mn680C,ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        mov ax,0x4fba
        push ds
        push ax
        call far ptr helper_2
        mov word ptr mn680E,0x0
    }
}
