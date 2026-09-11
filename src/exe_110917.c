extern int __near mn680A;
extern int __near mn680C;
extern int __near mn4FC0;
extern int __near mn6806;
extern int __near mn4FC2;
extern int __near mn6808;
void far helper_0(void);
int far exe_110917(int a)
{
    _asm {
        sub sp,0x6
        mov ax,0xffff
        mov mn680A,ax
        mov mn680C,ax
        mov ax,0x1
        push ax
        push word ptr [bp+0x6]
        mov ax,0x15
        push ax
        mov ax,0x4fba
        push ds
        push ax
        call far ptr helper_0
        add sp,0xa
        mov ax,mn4FC0
        mov mn6806,ax
        mov ax,mn4FC2
        mov mn6808,ax
        mov word ptr [bp-0x4],0x4fd0
        mov word ptr [bp-0x6],0x5160
L3A:
        mov bx,[bp-0x4]
        mov al,[bx]
        mov bx,[bp-0x6]
        mov [bx],al
        mov bx,[bp-0x4]
        mov cl,[bx+0x2]
        mov bx,[bp-0x6]
        mov [bx+0x1],cl
        mov bx,[bp-0x4]
        add al,[bx+0x4]
        mov bx,[bp-0x6]
        dec al
        mov [bx+0x2],al
        mov bx,[bp-0x4]
        add cl,[bx+0x6]
        mov bx,[bp-0x6]
        dec cl
        mov [bx+0x3],cl
        add word ptr [bp-0x4],0x14
        add word ptr [bp-0x6],0x4
        cmp word ptr [bp-0x6],0x5188
        jc short $-63
    }
}
