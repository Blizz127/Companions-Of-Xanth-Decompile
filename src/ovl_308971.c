extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_308971(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+39
        jmp L101
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L101
L1A:
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0x5a
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp L103
        nop
L31:
        mov ax,mn6A06
        cmp ax,0x5a
        jz short $+98
        jna short $+5
        jmp L101
L3E:
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+31
        sub al,0x19
        jz short $+9
        sub al,0x19
        jz short $+55
        jmp L101
L51:
        push word ptr mn6A04
        call far ptr helper_1
L5A:
        mov sp,bp
L5C:
        mov ax,0x1
        jmp L103
        nop
L63:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x14
L77:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_3
        jmp short $-39
L83:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x15
        jmp short $-32
L99:
        mov ax,mn6A02
        sub ax,0x8b
        jz short $+56
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
LC8:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
        jmp short $-121
LD7:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x16
        jmp short $-54
        nop
L101:
        xor ax,ax
L103:
    }
}
