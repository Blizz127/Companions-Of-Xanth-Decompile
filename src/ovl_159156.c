extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
extern char __near mb0364;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_159156(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+63
        jmp LAB
L0F:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp LAB
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+8
        mov ax,0x17
        jmp short $+44
        nop
L33:
        mov ax,0x5a06
        push ax
        mov ax,0x2c6
L3A:
        push ax
        call far ptr helper_1
L40:
        add sp,0x4
L43:
        mov ax,0x1
        jmp short $+103
        nop
L49:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+21
        jmp short $+85
        nop
L59:
        mov ax,0x16
L5C:
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_2
        jmp short $-38
        nop
L69:
        cmp word ptr mn0256,0x184
        jnz short $+50
        mov ax,0xe
        push ax
        mov ax,0x187
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+30
        mov ax,0x5a01
        push ax
        mov ax,0x2c5
        push ax
        call far ptr helper_1
        add sp,0x4
        mov byte ptr mb0364,0x1
        call far ptr helper_4
        jmp short $-92
LA1:
        mov ax,0x5a06
        push ax
        mov ax,0x2c7
        jmp short $-110
        nop
LAB:
        xor ax,ax
LAD:
    }
}
