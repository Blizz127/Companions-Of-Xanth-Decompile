extern int __near mn6A06;
extern char __near mb0327;
extern int __near mn6A04;
extern char __near mb0334;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_162076(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+81
        jmp LBF
L0F:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp LBF
L1A:
        cmp byte ptr mb0327,0x0
        jz short $+89
        cmp word ptr mn6A04,0x100
        jnz short $+32
        mov ax,0x38
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov ax,0x100
        push ax
        call far ptr helper_1
        jmp short $+15
L47:
        mov ax,0x5a07
        push ax
        mov ax,0x221
L4E:
        push ax
        call far ptr helper_2
L54:
        mov sp,bp
L56:
        mov ax,0x1
        jmp short $+104
L5B:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+11
        jmp short $+87
        nop
L6B:
        mov ax,0x36
        jmp short $+13
        nop
L71:
        cmp byte ptr mb0327,0x0
        jnz short $+17
L78:
        mov ax,0x37
L7B:
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_0
        jmp short $-49
L87:
        cmp byte ptr mb0334,0x0
        jnz short $+41
        mov ax,0x5a07
        push ax
        mov ax,0x20e
        push ax
        call far ptr helper_2
        add sp,0x4
        cmp byte ptr mb0334,0x0
        jz short $-77
        xor ax,ax
        push ax
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_3
        jmp short $-94
        nop
LB5:
        mov ax,0x5a07
        push ax
        mov ax,0x21b
        jmp short $-110
        nop
LBF:
        xor ax,ax
LC1:
    }
}
