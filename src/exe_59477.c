extern char __near mb0784;
extern int __near mn69F4;
extern int __near mn0056;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_59477(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x2
        cmp byte ptr mb0784,0x0
        jz short $+45
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x2
        cmp ax,mn69F4
        jz short $+28
        cmp word ptr mn0056,0x0
        jz short $+9
        cmp word ptr mn0056,0x1
        jnz short $+14
L35:
        mov ax,0x20
        push ax
        call far ptr helper_2
        add sp,0x2
L41:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_3
    }
}
