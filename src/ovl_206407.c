extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_206407(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp short $+123
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+114
        mov ax,0x2b
L1A:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+96
        nop
        nop
L2D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+62
        ja short $+82
        sub al,0x8
        jz short $+16
        sub al,0xa
        jz short $+18
        dec al
        jz short $+20
        sub al,0x19
        jz short $+22
        jmp short $+64
L49:
        mov ax,0x28
        jmp short $-50
        nop
L4F:
        mov ax,0x2a
        jmp short $-56
        nop
L55:
        mov ax,0x26
        jmp short $-62
        nop
L5B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x27
        jmp short $-85
L71:
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x29
        jmp short $-107
L87:
        xor ax,ax
L89:
    }
}
