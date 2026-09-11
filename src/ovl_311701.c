extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_311701(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+97
        jmp LD7
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LD7
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+24
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x4a
        jmp short $+23
L43:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x4b
L58:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L65:
        mov ax,0x1
        jmp short $+113
        nop
L6B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+96
        ja short $+100
        cmp al,0x13
        jz short $+60
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xa
        jz short $+36
        jmp short $+84
L85:
        sub al,0x2c
        jz short $+62
        sub al,0x13
        jz short $+64
        jmp short $+74
L8F:
        xor ax,ax
        push ax
        mov ax,0x1ba
        push ax
        push word ptr mn6A06
        call far ptr helper_3
        add sp,0x6
        jmp short $+55
        nop
LA5:
        mov ax,0xa
        push ax
        call far ptr helper_4
        add sp,0x2
        jmp short $-76
LB3:
        mov ax,0x46
LB6:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-94
LC5:
        mov ax,0x48
        jmp short $-18
        nop
LCB:
        mov ax,0x49
        jmp short $-24
        nop
LD1:
        mov ax,0x47
        jmp short $-30
        nop
LD7:
        xor ax,ax
LD9:
    }
}
