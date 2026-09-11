extern int __near mn02B4;
extern int __near mn02A8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_128544(int a)
{
    _asm {
        sub sp,0x4
        inc word ptr mn02B4
        mov ax,mn02B4
        dec ax
        jz short $+14
        dec ax
        jz short $+21
        dec ax
        jz short $+26
        dec ax
        jz short $+31
        jmp short $+39
        nop
L19:
        mov word ptr [bp-0x4],0x2773
        mov word ptr [bp-0x2],ds
        jmp short $+28
L23:
        mov word ptr [bp-0x4],0x19
        jmp short $+16
        nop
L2B:
        mov word ptr [bp-0x4],0x1a
        jmp short $+8
        nop
L33:
        mov word ptr [bp-0x4],0x1b
L38:
        mov word ptr [bp-0x2],0xf017
L3D:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x2780
        push ds
        push ax
        call far ptr helper_0
        add sp,0x8
        cmp word ptr mn02B4,0x4
        jnz short $+46
        mov ax,0xb
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0xbb8
        push ax
        call far ptr helper_2
        add sp,0x2
        mov word ptr mn02A8,0x7
        mov ax,0x5a
        push ax
        call far ptr helper_3
        add sp,0x2
        jmp short $+15
L83:
        mov ax,0x1
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_4
L90:
        mov ax,0x1
    }
}
