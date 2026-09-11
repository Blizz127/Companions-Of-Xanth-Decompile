extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn02A6;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_154835(int a)
{
    _asm {
        sub sp,0x6
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp L9D
L12:
        jmp L14F
L15:
        mov ax,mn6A06
        sub ax,0x33
        jz short $+10
        sub ax,0x5
        jz short $+5
        jmp L14F
L25:
        cmp word ptr mn0256,0x94
        jnz short $+9
        cmp word ptr mn6A02,0x1f
        jz short $+69
L34:
        cmp word ptr mn0256,0x97
        jz short $+61
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x44
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L70:
        mov ax,0x1
        jmp L151
        nop
L77:
        push word ptr mn6A04
        cmp word ptr mn0256,0x97
        jnz short $+8
        mov ax,0x95
        jmp short $+6
        nop
L89:
        mov ax,0x96
L8C:
        push ax
        mov ax,0xd
        push ax
L91:
        call far ptr helper_2
        add sp,0x6
        jmp L151
        nop
L9D:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L149
LA8:
        jna short $+5
        jmp L14F
LAD:
        sub al,0xd
        jz short $+18
        sub al,0x6
        jz short $+78
        sub al,0x2c
        jz short $+116
        sub al,0x5
        jz short $+118
        jmp L14F
        nop
LC1:
        cmp word ptr mn0256,0x8c
        jz short $+38
        cmp word ptr mn0256,0x80
        jz short $+30
        push word ptr mn6A02
        cmp word ptr mn0256,0x97
        jnz short $+8
        mov ax,0x95
        jmp short $+6
        nop
LE3:
        mov ax,0x96
LE6:
        push ax
        push word ptr mn6A06
        jmp short $-90
LED:
        mov ax,0x43
LF0:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L70
        nop
L101:
        cmp word ptr mn02A6,0x0
        jng short $+11
        mov ax,0x3f
        mov dx,0xf008
        jmp short $+8
        nop
L111:
        mov ax,0x2ab9
        mov dx,ds
L116:
        push dx
        push ax
        mov ax,0x3e
L11B:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L70
L12B:
        mov ax,0x40
        jmp short $-62
        nop
L131:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x41
        jmp short $-43
        nop
L149:
        mov ax,0x42
        jmp short $-92
        nop
L14F:
        xor ax,ax
L151:
    }
}
