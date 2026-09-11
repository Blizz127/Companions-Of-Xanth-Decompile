extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_310633(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp L1CD
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L1CD
L1A:
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
        mov ax,0x39
L40:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp L1CF
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x4d
        jnz short $+5
        jmp L19D
L5E:
        jna short $+5
        jmp L1CD
L63:
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+96
        sub al,0x19
        jnz short $+5
        jmp L137
L72:
        sub al,0x19
        jnz short $+5
        jmp L197
L79:
        jmp L1CD
        nop
L7D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+29
        mov ax,0x39ee
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x35
        jmp short $-105
LAB:
        mov ax,0x36
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-125
LC9:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x39d9
        jmp short $+5
LE1:
        mov ax,0x39de
LE4:
        push ds
        push ax
        mov ax,0x30
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+36
        push word ptr mn6A04
        mov ax,0x1bb
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+17
        mov ax,0x31
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L12A:
        mov ax,0x2e
        push ax
        call far ptr helper_5
        jmp L4A
        nop
L137:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x32
        jmp L40
        nop
L151:
        push word ptr mn6A04
        mov ax,0x1bb
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x33
        jmp L40
        nop
L16B:
        mov ax,0x34
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        mov sp,bp
        mov ax,0x39e5
        push ds
        push ax
        call far ptr helper_7
        jmp L4A
        nop
L197:
        mov ax,0x37
        jmp L40
L19D:
        mov ax,0x1ba
        push ax
        mov ax,0x1bb
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jnz short $+9
        mov ax,0x38
        jmp L40
        nop
L1B7:
        push word ptr mn6A02
        mov ax,0x1bb
        push ax
        push word ptr mn6A06
        call far ptr helper_8
        mov sp,bp
        jmp short $+5
        nop
L1CD:
        xor ax,ax
L1CF:
    }
}
