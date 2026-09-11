extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_201205(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+96
        jmp LE5
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LE5
L1E:
        push word ptr mn0256
        mov ax,0x11
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+9
        mov ax,0x31b2
        mov dx,ds
        jmp short $+5
L39:
        xor ax,ax
        cwd
L3C:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
L66:
        mov ax,0x1
        jmp short $+126
        nop
        nop
L6D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+108
        ja short $+112
        sub al,0xa
        jz short $+8
        sub al,0x9
        jz short $+56
        jmp short $+102
L81:
        push word ptr mn0256
        mov ax,0x11
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+20
        mov ax,0x1e
L98:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-63
LA7:
        mov ax,0x1
        push ax
        call far ptr helper_3
        add sp,0x2
        jmp short $-77
LB5:
        mov ax,0x1b
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        push word ptr mn0256
        mov ax,0x11
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $-113
        mov ax,0x1c
        jmp short $-68
        nop
LDF:
        mov ax,0x1d
        jmp short $-74
        nop
LE5:
        xor ax,ax
LE7:
    }
}
