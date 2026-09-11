extern int __near mn6DFC;
extern int __near mn6344;
extern int __near mn6DFE;
extern int __near mn6348;
extern int __near mn634A;
extern int __near mn6346;
void far helper_0(void);
int far exe_83742(int a)
{
    _asm {
        sub sp,0x8
        mov word ptr [bp-0x8],0x630c
L08:
        mov bx,[bp-0x8]
        mov word ptr [bx],0x0
        mov byte ptr [bx+0x3],0xfe
        sub ax,ax
        mov [bx+0x10],ax
        mov [bx+0xe],ax
        mov [bx+0x14],ax
        mov [bx+0x12],ax
        mov [bx+0x18],ax
        mov [bx+0x16],ax
        add word ptr [bp-0x8],0x1a
        cmp word ptr [bp-0x8],0x6340
        jc short $-40
        mov word ptr mn6DFC,0x18
        mov word ptr mn6344,0xf
        mov mn6DFE,ax
        mov mn6348,ax
        mov mn634A,ax
        mov ax,0xffff
        mov mn6346,ax
        push ax
        call far ptr helper_0
    }
}
