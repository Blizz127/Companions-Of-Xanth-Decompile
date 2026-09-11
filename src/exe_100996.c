extern int __near mn6450;
extern int __near mn6452;
extern int __near mn6454;
extern int __near mn6456;
extern int __near mn6458;
void far helper_0(void);
void far helper_1(void);
int far exe_100996(int a)
{
    _asm {
        sub sp,0x2
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov mn6450,ax
        mov mn6452,dx
        mov ax,[bp+0xa]
        mov mn6454,ax
        mov mn6456,ax
        sub ax,0x140
        neg ax
        mov mn6458,ax
        mov ax,0xfd85
        mov dx,0x8a7
        push dx
        push ax
        cmp word ptr [bp+0xc],0x0
        jz short $+10
        mov ax,0xfeca
        mov dx,0x8a7
        jmp short $+8
L3F:
        mov ax,0xfe2d
        mov dx,0x8a7
L45:
        push dx
        push ax
        mov ax,0x1596
        mov cx,0x3420
        push cx
        push ax
        call far ptr helper_1
    }
}
