extern int __near mn02C2;
extern int __near mn02A8;
extern char __near mb0329;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_195539(int a)
{
    _asm {
        sub sp,0x4
        inc word ptr mn02C2
        mov ax,0x1
        push ax
        mov ax,0xff
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+73
        mov ax,mn02C2
        dec ax
        jz short $+14
        dec ax
        jz short $+19
        dec ax
        jz short $+24
        dec ax
        jz short $+29
        jmp short $+37
        nop
lbl2D:
        mov word ptr [bp-0x4],0x4e
        jmp short $+24
        nop
lbl35:
        mov word ptr [bp-0x4],0x4f
        jmp short $+16
        nop
lbl3D:
        mov word ptr [bp-0x4],0x50
        jmp short $+8
        nop
lbl45:
        mov word ptr [bp-0x4],0x51
lbl4A:
        mov word ptr [bp-0x2],0xf021
lbl4F:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x30fe
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
lbl62:
        cmp word ptr mn02C2,0x4
        jnl short $+22
        mov ax,0x1
        push ax
        mov ax,0x1b
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp lbl107
        nop
lbl7D:
        mov ax,0x1
        push ax
        mov ax,0xff
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+38
        xor ax,ax
        push ax
        push ax
        mov ax,0xff
        push ax
        call far ptr helper_3
        add sp,0x6
        mov word ptr mn02A8,0x10
        mov ax,0x5a
        push ax
        call far ptr helper_4
        add sp,0x2
        jmp short $+84
lblB5:
        xor ax,ax
        push ax
        push ax
        mov ax,0xff
        push ax
        call far ptr helper_3
        add sp,0x6
        mov byte ptr mb0329,0x1
        cmp word ptr mn0256,0x102
        jnz short $+23
        call far ptr helper_5
        call far ptr helper_6
        call far ptr helper_7
        mov ax,0x52
        jmp short $+6
        nop
lblE7:
        mov ax,0x53
lblEA:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_8
lbl107:
        mov ax,0x1
    }
}
