extern int __near mn4EA0;
extern int __near mn642C;
extern char __near mb4F28;
extern int __near mn4F28;
void far helper_0(void);
int far exe_99842(void)
{
    _asm {
        mov word ptr mn4EA0,0x1
        mov word ptr mn642C,0xffff
        mov al,mb4F28
        and ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x2
        mov bx,mn4F28
        cmp byte ptr [bx+0x4f2a],0x0
        jz short $+19
        dec byte ptr [bx+0x4f2a]
        jnz short $+13
        cmp word ptr mn4F28,0x0
        jng short $+6
        dec word ptr mn4F28
L37:
        mov word ptr mn4EA0,0x0
        retf
    }
}
