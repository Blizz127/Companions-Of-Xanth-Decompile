extern int __near mn4EA0;
extern int __near mn4E9E;
extern char __near mb4E9E;
extern int __near mn643A;
extern int __near mn6438;
extern int __near mn643E;
extern int __near mn643C;
void far helper_0(void);
int far exe_99492(int a)
{
    _asm {
        sub sp,0x4
        mov ax,mn4EA0
        mov [bp-0x2],ax
        mov word ptr mn4EA0,0x1
        mov ax,mn4E9E
        mov [bp-0x4],ax
        or ax,ax
        jz short $+35
        test byte ptr mb4E9E,0x1
        jz short $+28
        and byte ptr mb4E9E,0xfe
        push word ptr mn643A
        push word ptr mn6438
        push word ptr mn643E
        push word ptr mn643C
        call far ptr helper_0
L3A:
        mov ax,[bp-0x2]
        mov mn4EA0,ax
        mov al,[bp-0x4]
        and ax,0x1
    }
}
