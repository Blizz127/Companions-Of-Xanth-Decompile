extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
int far ovl_75098(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LB7
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB7
L1A:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2d
L40:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+106
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+72
        ja short $+94
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+34
        sub al,0x19
        jz short $+8
        sub al,0x18
        jz short $+32
        jmp short $+76
L6D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2b
        jmp short $-65
L83:
        mov ax,0x29
        jmp short $-70
        nop
L89:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2a
        jmp short $-93
L9F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c
        jmp short $-116
        nop
LB7:
        xor ax,ax
LB9:
    }
}
