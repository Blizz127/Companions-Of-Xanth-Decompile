extern int __near mn644E;
extern int __near mn644A;
extern int __near mn644C;
extern int __near mn6450;
extern int __near mn6452;
extern int __near mn6454;
extern int __near mn6456;
extern int __near mn6458;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_101087(int a)
{
    _asm {
        sub sp,0x6
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov mn644E,ax
        les bx, [bp+0x6]
        mov ax,es:[bx]
        mov dx,es:[bx+0x2]
        mov mn644A,ax
        mov mn644C,dx
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_1
        add sp,0x4
        mov mn6450,ax
        mov mn6452,dx
        mov ax,[bp+0xe]
        mov mn6454,ax
        mov mn6456,ax
        sub ax,0x140
        neg ax
        mov mn6458,ax
        mov ax,0xfda3
        mov dx,0x8a7
        push dx
        push ax
        cmp word ptr [bp+0x10],0x0
        jz short $+10
        mov ax,0xff4e
        mov dx,0x8a7
        jmp short $+22
L61:
        cmp word ptr [bp+0x12],0x0
        jz short $+10
        mov ax,0xfeca
        mov dx,0x8a7
        jmp short $+8
L6F:
        mov ax,0xfe2d
        mov dx,0x8a7
L75:
        push dx
        push ax
        mov ax,0x1596
        mov cx,0x3420
        push cx
        push ax
        call far ptr helper_2
    }
}
