extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_278981(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+109
        jmp LF1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LF1
L1A:
        mov ax,mn6A04
        sub ax,0x16c
        jz short $+9
        dec ax
        dec ax
        jz short $+61
        jmp LF1
L29:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x19
L4F:
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5B:
        mov ax,0x1
        jmp LF3
L61:
        mov ax,0x16c
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_2
        mov sp,bp
        jmp short $+127
        nop
L77:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+100
        ja short $+114
        cmp al,0x2c
        jz short $+26
        ja short $+14
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+38
        jmp short $+98
        nop
        nop
L93:
        sub al,0x38
        jz short $+52
        sub al,0xc
        jz short $+48
        jmp short $+86
L9D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        jmp short $-98
LB3:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x16
        jmp short $-120
LC9:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
        jmp L4F
LE1:
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x2
        jmp L5B
        nop
LF1:
        xor ax,ax
LF3:
    }
}
