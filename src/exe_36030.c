extern int __near mn69F8;
extern int __near mn5C32;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far exe_36030(int a)
{
    _asm {
        sub sp,0xc
        call far ptr helper_0
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,mn69F8
        mov mn5C32,ax
        mov ax,[bp+0xc]
        mov [bp-0x4],ax
        les bx, [bp+0x6]
        cmp word ptr es:[bx],0x0
        jnz short $+5
        jmp LB1
L2C:
        mov [bp-0xc],bx
        mov word ptr [bp-0xa],es
L32:
        push word ptr es:[bx]
        call far ptr helper_2
        add sp,0x2
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        mov ax,[bp-0x4]
        inc ax
        push ax
        mov ax,[bp+0xa]
        inc ax
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0xffff
        push ax
        xor cx,cx
        push cx
        call far ptr helper_4
        add sp,0x4
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        call far ptr helper_5
        add sp,0x4
        push word ptr [bp-0x4]
        push word ptr [bp+0xa]
        call far ptr helper_3
        add sp,0x4
        mov ax,0xffff
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_4
        add sp,0x4
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        call far ptr helper_5
        add sp,0x4
        mov ax,mn69F8
        add [bp-0x4],ax
        add word ptr [bp-0xc],0x2
        les bx, [bp-0xc]
        cmp word ptr es:[bx],0x0
        jnz short $-125
LB1:
        xor ax,ax
        push ax
        mov cx,0x8
        push cx
        push word ptr [bp-0x4]
        mov cx,0x31
        push cx
        push word ptr [bp+0xc]
        mov cx,0x2
        push cx
        push ax
        call far ptr helper_6
        add sp,0xe
        call far ptr helper_7
        mov ax,[bp-0x4]
    }
}
