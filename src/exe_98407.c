extern int __near mn4EDE;
extern int __near mn6444;
extern int __near mn6448;
extern int __near mn6446;

int far exe_98407(int a)
{
    _asm {
        sub sp,0x6
        cmp word ptr mn4EDE,0x0
        jz short $+36
        mov ax,mn6444
        mov [bp-0x2],ax
        mov ax,mn6448
        mov [bp-0x4],ax
        mov ax,mn6446
        mov [bp-0x6],ax
        mov ax,0x14
        mov bx,[bp-0x2]
        mov es,bx
        mov cx,[bp-0x4]
        mov dx,[bp-0x6]
        int 0x33
L2C:
        mov word ptr mn4EDE,0x0
    }
}
