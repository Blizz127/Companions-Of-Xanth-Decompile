extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_271136(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L197
L0F:
        jmp L225
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+14
        sub ax,0x17
        jnz short $+5
        jmp L143
L23:
        jmp L225
        nop
L27:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+43
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        jmp L130
L63:
        cmp word ptr mn6A04,0x15e
        jnz short $+78
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
        jmp L13D
        nop
LB7:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+38
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f
LE0:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $+80
LEF:
        cmp word ptr mn6A04,0x177
        jnz short $+20
        mov ax,0x20
LFA:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $+54
L109:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
L130:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
L13D:
        mov ax,0x1
        jmp L227
L143:
        cmp word ptr mn6A04,0x124
        jz short $+5
        jmp L225
L14E:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
        jmp short $-87
        nop
L197:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+112
        jna short $+5
        jmp L225
L1A4:
        sub al,0x13
        jz short $+15
        sub al,0x25
        jz short $+75
        sub al,0xc
        jz short $+71
        jmp short $+117
        nop
        nop
        nop
L1B5:
        mov ax,0x158
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        push word ptr mn6A04
        mov ax,0x15e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L13D
L1EE:
        mov ax,0x19
        jmp LFA
        nop
L1F5:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1a
        jmp LE0
L20D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
        jmp LE0
L225:
        xor ax,ax
L227:
    }
}
