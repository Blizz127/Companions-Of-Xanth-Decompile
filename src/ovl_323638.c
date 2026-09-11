extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_323638(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+113
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+104
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
L3D:
        mov dx,0xf04c
        push dx
        push ax
        call far ptr helper_1
L47:
        mov sp,bp
        mov ax,0x1
        jmp short $+51
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+34
        ja short $+38
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+18
        sub al,0x19
        jnz short $+26
L65:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-39
        nop
L71:
        mov ax,0x8
        jmp short $-55
        nop
L77:
        mov ax,0x9
        jmp short $-61
        nop
L7D:
        xor ax,ax
L7F:
    }
}
