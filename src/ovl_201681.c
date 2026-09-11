extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_201681(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+125
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+116
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c
L3D:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+63
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+46
        ja short $+50
        sub al,0xe
        jz short $+16
        sub al,0x5
        jz short $+18
        sub al,0x2f
        jz short $+20
        sub al,0x2
        jz short $+22
        jmp short $+32
L6B:
        mov ax,0x2a
        jmp short $-49
        nop
L71:
        mov ax,0x27
        jmp short $-55
        nop
L77:
        mov ax,0x2b
        jmp short $-61
        nop
L7D:
        mov ax,0x28
        jmp short $-67
        nop
L83:
        mov ax,0x29
        jmp short $-73
        nop
L89:
        xor ax,ax
L8B:
    }
}
