extern int __near mn51E2;
extern int __near mn51E0;
extern int __near mn51E4;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far exe_121724(void)
{
    _asm {
        cmp word ptr mn51E2,0x0
        jz short $+127
        dec word ptr mn51E2
        call far ptr helper_0
        mov bx,mn51E2
        add bx,bx
        push word ptr [bx+0x6980]
        call far ptr helper_1
        add sp,0x2
        xor ax,ax
        push ax
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x14
        imul word ptr mn51E2
        add ax,0x6982
        push ds
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x14
        imul word ptr mn51E2
        add ax,0x6982
        push ds
        push ax
        call far ptr helper_4
        add sp,0x4
        call far ptr helper_5
        mov ax,0x5241
        push ds
        push ax
        push word ptr mn51E0
        call far ptr helper_6
        add sp,0x6
        cmp word ptr mn51E2,0x0
        jnz short $+14
        push word ptr mn51E4
        call far ptr helper_7
        add sp,0x2
L7F:
        call far ptr helper_8
L84:
        retf
    }
}
