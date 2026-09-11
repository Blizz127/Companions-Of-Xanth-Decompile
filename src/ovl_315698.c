extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_315698(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp LBF
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LBF
L1A:
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
        mov ax,0x32
L40:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L4C:
        mov ax,0x1
        jmp short $+114
        nop
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x49
        jz short $+96
        ja short $+100
        cmp al,0x2c
        jz short $+66
        ja short $+16
        sub al,0x8
        jz short $+26
        sub al,0x7
        jz short $+28
        sub al,0x4
        jz short $+46
        jmp short $+80
L71:
        sub al,0x3f
        jz short $+52
        sub al,0x5
        jz short $+54
        dec al
        jz short $+56
        jmp short $+66
L7F:
        mov ax,0x2d
        jmp short $-66
        nop
L85:
        mov ax,0x31
L88:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        call far ptr helper_2
        jmp short $-77
L9B:
        mov ax,0x2a
        jmp short $-22
        nop
LA1:
        mov ax,0x2c
        jmp short $-28
        nop
LA7:
        mov ax,0x30
        jmp short $-106
        nop
LAD:
        mov ax,0x2b
        jmp short $-112
        nop
LB3:
        mov ax,0x2e
        jmp short $-118
        nop
LB9:
        mov ax,0x2f
        jmp short $-52
        nop
LBF:
        xor ax,ax
LC1:
    }
}
