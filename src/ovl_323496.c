extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_323496(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+121
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+112
        push word ptr mn6A02
        mov ax,0x2
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
        mov ax,0x7
L3D:
        mov dx,0xf04c
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+59
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+42
        ja short $+46
        sub al,0x13
        jz short $+8
        sub al,0x19
        jz short $+10
        jmp short $+36
L63:
        mov ax,0x4
        jmp short $-41
        nop
L69:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x5
        jmp short $-64
L7F:
        mov ax,0x6
        jmp short $-69
        nop
L85:
        xor ax,ax
L87:
    }
}
