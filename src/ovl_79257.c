extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_79257(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LBF
L0E:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L9B
L19:
        jna short $+5
        jmp LBF
L1E:
        cmp al,0x2c
        jz short $+26
        ja short $+13
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+37
        jmp LBF
L2F:
        sub al,0x3a
        jz short $+30
        sub al,0xa
        jz short $+5
        jmp LBF
L3A:
        mov ax,0x1e
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
L4A:
        mov ax,0x1
        jmp short $+116
L4F:
        mov ax,0xa
        push ax
        mov ax,0x29
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        xor ax,ax
        cwd
        jmp short $+8
        nop
L69:
        mov ax,0x200d
        mov dx,ds
L6E:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        cmp word ptr mn6A04,0x2a
        jnz short $+8
        mov ax,0x2011
        jmp short $+6
        nop
L83:
        mov ax,0x201a
L86:
        push ds
        push ax
        mov ax,0x1c
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        jmp short $-78
        nop
L9B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        mov dx,0xf032
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp short $-115
LBF:
        xor ax,ax
LC1:
    }
}
