extern int __near mn5D78;
extern int __near mn5D7A;
extern int __near mn07E4;
extern int __near mn5D7E;
extern int __near mn5D7C;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_61592(int a)
{
    _asm {
        cmp word ptr [bp+0xa],0x1
        jnz short $+13
        mov ax,0x4
        push ax
        call far ptr helper_0
        mov sp,bp
L11:
        xor ax,ax
        push ax
        call far ptr helper_1
        mov sp,bp
        cmp word ptr [bp+0xa],0x1
        jnz short $+8
        mov ax,0x7e6
        jmp short $+6
        nop
L27:
        mov ax,0x7e8
L2A:
        push ds
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_2
        mov sp,bp
        mov mn5D78,ax
        mov mn5D7A,dx
        mov ax,dx
        or ax,mn5D78
        jnz short $+25
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        xor ax,ax
        mov dx,0xf001
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        jmp short $+39
        nop
L5F:
        mov ax,[bp+0xa]
        mov mn07E4,ax
        dec ax
        jnz short $+29
        xor ax,ax
        push ax
        call far ptr helper_4
        mov sp,bp
        sub ax,ax
        mov mn5D7E,ax
        mov mn5D7C,ax
        mov ax,0x1
        push ax
        call far ptr helper_5
L83:
    }
}
