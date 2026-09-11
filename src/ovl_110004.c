extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_110004(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LE7
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LC1
L16:
        jna short $+5
        jmp LE7
L1B:
        sub al,0xf
        jz short $+14
        sub al,0x4
        jz short $+58
        sub al,0x31
        jz short $+116
        jmp LE7
        nop
L2B:
        mov ax,0x16
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0xfa0
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x5a03
        push ax
        mov ax,0x17f
        push ax
        call far ptr helper_2
L52:
        mov sp,bp
L54:
        mov ax,0x1
        jmp LE9
        nop
L5B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        mov ax,0x3
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x2565
        jmp short $+5
L85:
        mov ax,0x256d
L88:
        push ds
        push ax
        mov ax,0x13
L8D:
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_0
        jmp short $-69
L99:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        jmp short $-50
LC1:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
        mov dx,0xf00a
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L54
        nop
LE7:
        xor ax,ax
LE9:
    }
}
