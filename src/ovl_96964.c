extern int __near mn0290;
extern int __near mn02A8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_96964(int a)
{
    _asm {
        sub sp,0x4
        mov ax,mn0290
        sub ax,0x6
        jz short $+12
        sub ax,0x4
        jz short $+27
        dec ax
        jz short $+32
        jmp short $+56
L15:
        mov word ptr [bp-0x4],0x26
        mov word ptr [bp-0x2],0xf016
        mov ax,0xe
        push ax
        mov ax,0x5c
        jmp short $+28
        nop
L29:
        mov word ptr [bp-0x4],0x28
        jmp short $+8
        nop
L31:
        mov word ptr [bp-0x4],0x27
L36:
        mov word ptr [bp-0x2],0xf016
        mov ax,0xe
        push ax
        mov ax,0x5e
L42:
        push ax
        call far ptr helper_0
        add sp,0x4
L4B:
        call far ptr helper_1
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x23c6
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x2710
        push ax
        call far ptr helper_3
        add sp,0x2
        call far ptr helper_4
        mov word ptr mn02A8,0x3
        mov ax,0x5a
        push ax
        call far ptr helper_5
        mov ax,0x1
    }
}
