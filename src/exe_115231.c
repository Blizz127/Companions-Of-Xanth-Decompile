extern int __near mn51E0;
void far helper_0(void);
int far exe_115231(int a)
{
    _asm {
        sub sp,0x2
        mov bx,mn51E0
        add bx,bx
        add bx,0x68d0
        mov [bp-0x2],bx
        cmp word ptr [bx],0x0
        jz short $+52
        mov cl,0x4
        mov word ptr [bx],0x0
        mov ax,mn51E0
        shl ax,cl
        add ax,0x68e0
        push ds
        push ax
        push word ptr mn51E0
        call far ptr helper_0
        mov cl,0x4
        mov bx,mn51E0
        shl bx,cl
        mov byte ptr [bx+0x68e0],0x0
        mov bx,mn51E0
        add bx,bx
        mov word ptr [bx+0x68d0],0x1
L47:
    }
}
