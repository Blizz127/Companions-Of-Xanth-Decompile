extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0314;
extern char __near mb0313;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_139415(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+85
        jmp L141
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L141
L1A:
        cmp word ptr mn6A04,0xa7
        jz short $+41
        cmp word ptr mn6A04,0xa2
        jz short $+33
        cmp word ptr mn6A04,0xa6
        jz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        jmp short $+6
        nop
L49:
        mov ax,0x17
L4C:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L58:
        mov ax,0x1
        jmp L143
        nop
L5F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+124
        jna short $+5
        jmp L141
L6C:
        cmp al,0x2c
        jz short $+29
        ja short $+15
        sub al,0x8
        jz short $+23
        sub al,0xb
        jz short $+35
        jmp L141
        nop
        nop
L7F:
        sub al,0x38
        jz short $+64
        sub al,0xc
        jz short $+66
        jmp L141
        nop
L8B:
        mov ax,0x14
L8E:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        jmp L123
L9B:
        cmp byte ptr mb0314,0x0
        jnz short $+7
        mov ax,0x10
        jmp short $+5
LA7:
        mov ax,0x11
LAA:
        mov dx,0xf010
        push dx
        push ax
        mov ax,0xf
LB2:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-103
LC1:
        mov ax,0x16
        jmp short $-54
        nop
LC7:
        cmp byte ptr mb0314,0x0
        jz short $+11
        mov ax,0x13
        mov dx,0xf010
        jmp short $+6
        nop
LD7:
        xor ax,ax
        cwd
LDA:
        push dx
        push ax
        mov ax,0x12
        jmp short $-45
LE1:
        cmp byte ptr mb0313,0x0
        jnz short $+41
        mov ax,0xb
        push ax
        call far ptr helper_2
        add sp,0x2
        mov byte ptr mb0313,0x1
        mov ax,0xb
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x600
        push ax
        mov ax,0x329
        jmp short $+17
        nop
L10F:
        cmp byte ptr mb0314,0x0
        jnz short $+21
        mov ax,0x600
        push ax
        mov ax,0x32a
L11D:
        push ax
        call far ptr helper_3
L123:
        add sp,0x4
        jmp L58
L129:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
        jmp LB2
L141:
        xor ax,ax
L143:
    }
}
