extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_250397(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+11
        dec ax
        dec ax
        jz short $+127
        jmp L11B
        nop
        nop
L11:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+5
        jmp L11B
L21:
        mov ax,mn6A04
        sub ax,0x124
        jz short $+60
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
        cmp word ptr mn6A06,0x38
        jnz short $+8
        mov ax,0x343a
        jmp short $+6
        nop
L59:
        mov ax,0x343e
L5C:
        push ds
        push ax
        mov ax,0x3e
        jmp short $+22
L63:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3d
L77:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp L11D
L89:
        mov ax,mn6A06
        cmp ax,0x4d
        jz short $+84
        jna short $+5
        jmp L11B
L96:
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+35
        sub al,0x19
        jz short $+31
        sub al,0x19
        jz short $+57
        jmp short $+117
        nop
LA9:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x39
        jmp short $-70
LBF:
        mov ax,0x11
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+7
        mov ax,0x37
        jmp short $-94
LD7:
        mov ax,0x38
        jmp short $-99
        nop
LDD:
        mov ax,0x3a
        jmp short $-105
        nop
LE3:
        cmp word ptr mn6A02,0x127
        jnz short $+8
        mov ax,0x3b
        jmp short $-119
        nop
LF1:
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
        mov ax,0x3c
        jmp L77
        nop
L11B:
        xor ax,ax
L11D:
    }
}
