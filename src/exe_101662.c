extern int __near mn4F62;
extern int __near mn4F60;
extern int __near mn4F5E;
extern int __near mn4F5C;
extern int __near mn4F66;
extern int __near mn4F64;
extern int __near mn4F44;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_101662(int a)
{
    _asm {
        mov ax,mn4F62
        or ax,mn4F60
        jz short $+21
        push word ptr mn4F62
        push word ptr mn4F60
        mov ax,0x1c
        push ax
        call far ptr helper_0
        mov sp,bp
L1C:
        push word ptr mn4F5E
        push word ptr mn4F5C
        mov ax,0x1b
        push ax
        call far ptr helper_0
        mov sp,bp
        push word ptr mn4F66
        push word ptr mn4F64
        mov ax,0x23
        push ax
        call far ptr helper_0
        mov sp,bp
        cmp word ptr mn4F44,0x0
        jz short $+19
        push word ptr mn4F44
        call far ptr helper_1
        mov sp,bp
        mov word ptr mn4F44,0x0
L5A:
        cmp word ptr [bp+0x6],0x0
        jz short $+10
        xor ax,ax
        push ax
        call far ptr helper_2
L68:
    }
}
