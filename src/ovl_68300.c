extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_68300(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L8F
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+98
        ja short $+124
        sub al,0x8
        jz short $+14
        sub al,0x3
        jz short $+48
        sub al,0x8
        jz short $+66
        sub al,0x19
        jnz short $+108
L25:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x14
L39:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L45:
        mov ax,0x1
        jmp short $+73
        nop
L4B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x15
        jmp short $-38
L61:
        mov ax,0x13
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-44
L73:
        mov ax,0x1e70
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_0
        add sp,0x8
        push dx
        push ax
        mov ax,0x16
        jmp short $-84
L8F:
        xor ax,ax
L91:
    }
}
