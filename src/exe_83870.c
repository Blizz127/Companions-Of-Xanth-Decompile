extern int __near mn6340;
extern int __near mn6342;
void far helper_0(void);
int far exe_83870(int a)
{
    _asm {
        les bx, [bp+0x6]
        cmp word ptr es:[bx],0x0
        jz short $+94
        mov word ptr es:[bx],0x0
        mov byte ptr es:[bx+0x3],0xfe
        push word ptr es:[bx+0x10]
        push word ptr es:[bx+0xe]
        call far ptr helper_0
        mov sp,bp
        les bx, [bp+0x6]
        sub ax,ax
        mov es:[bx+0x10],ax
        mov es:[bx+0xe],ax
        push word ptr es:[bx+0x14]
        push word ptr es:[bx+0x12]
        call far ptr helper_0
        mov sp,bp
        les bx, [bp+0x6]
        sub ax,ax
        mov es:[bx+0x14],ax
        mov es:[bx+0x12],ax
        push word ptr es:[bx+0x18]
        push word ptr es:[bx+0x16]
        call far ptr helper_0
        les bx, [bp+0x6]
        sub ax,ax
        mov es:[bx+0x18],ax
        mov es:[bx+0x16],ax
L65:
        mov word ptr mn6340,0x630c
        mov word ptr mn6342,ds
    }
}
