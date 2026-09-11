extern int __near mn4EDE;
extern int __near mn6444;
extern int __near mn6448;
extern int __near mn6446;

int far exe_98339(int a)
{
    _asm {
        sub sp,0x6
        cmp word ptr mn4EDE,0x0
        jnz short $+53
        mov ax,0x14
        mov bx,0x8a7
        mov es,bx
        mov cx,0x1
        mov dx,0xf630
        int 0x33
        mov bx,es
        mov [bp-0x2],bx
        mov [bp-0x4],cx
        mov [bp-0x6],dx
        mov ax,[bp-0x2]
        mov mn6444,ax
        mov ax,[bp-0x4]
        mov mn6448,ax
        mov ax,[bp-0x6]
        mov mn6446,ax
        mov word ptr mn4EDE,0x0
L3D:
    }
}
