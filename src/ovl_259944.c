extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb030E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_259944(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LA7
L0F:
        jmp L15B
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+105
        jmp L15B
L23:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+45
        cmp word ptr mn6A04,0x149
        jz short $+37
        cmp word ptr mn6A04,0x14a
        jz short $+29
        cmp word ptr mn6A04,0x14b
        jz short $+21
        cmp word ptr mn6A04,0x14c
        jz short $+13
        cmp word ptr mn6A04,0x14d
        jz short $+5
        jmp L15B
L61:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x9
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
L7F:
        mov sp,bp
L81:
        mov ax,0x1
        jmp L15D
L87:
        cmp word ptr mn6A04,0x124
        jz short $+5
        jmp L15B
L92:
        xor ax,ax
        push ax
        mov ax,0x13f
        push ax
        mov ax,0x44
        push ax
        call far ptr helper_3
        mov sp,bp
        jmp L15D
LA7:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+62
        jna short $+5
        jmp L15B
LB4:
        sub al,0x13
        jz short $+13
        sub al,0x19
        jz short $+15
        sub al,0x18
        jz short $+17
        jmp L15B
LC3:
        mov ax,0x4
        jmp short $+62
        nop
LC9:
        mov ax,0x6
        jmp short $+56
        nop
LCF:
        cmp byte ptr mb030E,0x0
        jz short $+7
        mov ax,0x5
        jmp short $+43
LDB:
        mov ax,0xe19
        push ax
        mov ax,0x388
        push ax
        call far ptr helper_4
        jmp short $-105
        nop
LEB:
        mov ax,0x7
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        cmp byte ptr mb030E,0x0
        jz short $+18
        mov ax,0x8
L104:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        jmp short $+60
        nop
L111:
        mov ax,0x1
        push ax
        mov ax,0x14e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+46
        mov ax,0xb
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0xfa0
        push ax
        call far ptr helper_6
        add sp,0x2
        mov ax,0xe19
        push ax
        mov ax,0x378
L144:
        push ax
        call far ptr helper_4
L14A:
        add sp,0x4
        jmp L81
        nop
L151:
        mov ax,0xe19
        push ax
        mov ax,0x381
        jmp short $-20
        nop
L15B:
        xor ax,ax
L15D:
    }
}
