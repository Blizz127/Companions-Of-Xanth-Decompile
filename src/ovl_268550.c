extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0358;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_268550(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+77
        jmp LDB
L0F:
        mov ax,mn6A06
        sub ax,0x4f
        jnz short $+60
        cmp word ptr mn6A04,0x124
        jnz short $+52
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
        mov ax,0x37
L45:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L51:
        mov ax,0x1
        jmp LDD
L57:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+120
        ja short $+124
        sub al,0x2
        jz short $+12
        sub al,0x11
        jz short $+56
        sub al,0x31
        jz short $+70
        jmp short $+110
L6F:
        cmp word ptr mn6A02,0x155
        jz short $+102
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
        mov ax,0x36
        jmp short $-88
L9F:
        mov ax,0x33
LA2:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-94
LB1:
        cmp byte ptr mb0358,0x0
        jz short $+25
        mov ax,0x155
        push ax
        push word ptr mn6A04
        mov ax,0x38
        push ax
        call far ptr helper_2
        add sp,0x6
        jmp short $+17
        nop
LCF:
        mov ax,0x34
        jmp short $-48
        nop
LD5:
        mov ax,0x35
        jmp short $-54
        nop
LDB:
        xor ax,ax
LDD:
    }
}
