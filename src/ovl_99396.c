extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb02F3;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_99396(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+85
        jmp L101
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L101
L1A:
        cmp word ptr mn6A04,0x6d
        jnz short $+8
        mov ax,0xe
        jmp short $+41
        nop
L27:
        push word ptr mn6A04
        mov ax,0x6
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
        mov ax,0xf
L4D:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
L57:
        mov sp,bp
        mov ax,0x1
        jmp L103
L5F:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LF1
L6A:
        jna short $+5
        jmp L101
L6F:
        cmp al,0x13
        jz short $+68
        ja short $+14
        sub al,0x7
        jz short $+24
        dec al
        jz short $+38
        jmp L101
        nop
L81:
        sub al,0x2c
        jz short $+30
        sub al,0x2
        jz short $+68
        sub al,0x16
        jz short $+78
        jmp short $+116
L8F:
        cmp byte ptr mb02F3,0x0
        jz short $+7
        mov ax,0xc
        jmp short $-76
L9B:
        mov ax,0xd
        jmp short $-81
        nop
LA1:
        xor ax,ax
        push ax
        mov ax,0x6a
        push ax
        mov ax,0x2c
        push ax
LAC:
        call far ptr helper_2
        mov sp,bp
        jmp short $+80
LB5:
        mov ax,0x6c
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp short $-124
LCB:
        xor ax,ax
        push ax
        mov ax,0x6c
        push ax
        push word ptr mn6A06
        jmp short $-42
        nop
LD9:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        jmp L4D
LF1:
        mov ax,0x400
        push ax
        mov ax,0x206
        push ax
        call far ptr helper_3
        jmp L57
L101:
        xor ax,ax
L103:
    }
}
