extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_179311(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp L91
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+124
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
        mov ax,0x57
L3D:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
L47:
        mov sp,bp
        mov ax,0x1
        jmp short $+71
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+54
        ja short $+58
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+26
        jmp short $+42
L69:
        sub al,0x38
        jz short $+26
        sub al,0xc
        jz short $+22
        jmp short $+32
L73:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-53
        nop
L7F:
        mov ax,0x54
        jmp short $-69
        nop
L85:
        mov ax,0x55
        jmp short $-75
        nop
L8B:
        mov ax,0x56
        jmp short $-81
        nop
L91:
        xor ax,ax
L93:
    }
}
