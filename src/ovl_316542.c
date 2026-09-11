extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_316542(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp L95
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+128
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
        mov ax,0x45
L3D:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
L47:
        mov sp,bp
L49:
        mov ax,0x1
        jmp short $+75
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+52
        ja short $+62
        sub al,0x13
        jz short $+12
        sub al,0x19
        jz short $+30
        sub al,0x18
        jz short $+32
        jmp short $+48
L67:
        mov ax,0x42
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        call far ptr helper_2
        jmp short $-50
L7D:
        mov ax,0x44
        jmp short $-67
        nop
L83:
        mov ax,0x43
        jmp short $-73
        nop
L89:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-75
        nop
L95:
        xor ax,ax
L97:
    }
}
