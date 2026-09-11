extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_206551(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+125
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+116
        mov ax,0x2f
L1A:
        mov dx,0xf025
        push dx
L1E:
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+98
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+64
        ja short $+86
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+36
        jmp short $+70
L45:
        sub al,0x38
        jz short $+36
        sub al,0xc
        jz short $+32
        jmp short $+60
L4F:
        cmp word ptr mn6A06,0x2c
        jnz short $+7
        mov ax,0x31e5
        jmp short $+5
L5B:
        mov ax,0x31ea
L5E:
        push ds
        push ax
        mov ax,0x2c
        jmp short $-73
L65:
        mov ax,0x31d5
        push ds
        jmp short $-75
L6B:
        mov ax,0x2d
        jmp short $-84
        nop
L71:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2e
        jmp short $-108
        nop
L89:
        xor ax,ax
L8B:
    }
}
