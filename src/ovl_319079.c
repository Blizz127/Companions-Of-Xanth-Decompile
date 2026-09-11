extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_319079(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+107
        jmp LBF
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x10
        jz short $+5
        jmp LBF
L1F:
        cmp word ptr mn6A04,0x1c3
        jnz short $+24
        mov ax,0x1d2
        push ax
        push word ptr mn6A04
        mov ax,0x48
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp LC1
L3D:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
L63:
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_2
L6D:
        mov sp,bp
L6F:
        mov ax,0x1
        jmp short $+79
        nop
L75:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+16
        ja short $+66
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+18
        sub al,0x19
        jnz short $+54
L8B:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-39
        nop
L97:
        mov ax,0x7
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1ce
        push ax
        mov ax,0x1c3
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $-72
        mov ax,0xa
        jmp short $-89
        nop
LBF:
        xor ax,ax
LC1:
    }
}
