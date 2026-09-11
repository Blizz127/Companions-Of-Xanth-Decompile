extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_317028(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+53
        jmp L9F
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L9F
L1A:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x53
L2E:
        mov dx,0xf049
        push dx
L32:
        push ax
        call far ptr helper_1
        mov sp,bp
L3A:
        mov ax,0x1
        jmp short $+100
L3F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+76
        ja short $+88
        cmp al,0x13
        jz short $+52
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0x6
        jz short $+20
        jmp short $+72
L59:
        sub al,0x2c
        jz short $+42
        sub al,0x18
        jz short $+44
        jmp short $+62
L63:
        mov ax,0x51
        jmp short $-56
        nop
L69:
        mov ax,0x52
L6C:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        call far ptr helper_2
        jmp short $-67
L7F:
        mov ax,0x4f
        jmp short $-22
        nop
L85:
        mov ax,0x3a70
        push ds
        jmp short $-87
L8B:
        mov ax,0x50
        jmp short $-96
        nop
L91:
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x2
        jmp short $-99
L9F:
        xor ax,ax
LA1:
    }
}
