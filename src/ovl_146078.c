extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_146078(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1F5
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1C3
L16:
        jna short $+5
        jmp L1F5
L1B:
        cmp al,0x44
        jnz short $+5
        jmp L165
L22:
        jna short $+5
        jmp L1F5
L27:
        sub al,0x8
        jz short $+26
        dec al
        jnz short $+5
        jmp LBB
L32:
        sub al,0x6
        jnz short $+5
        jmp L131
L39:
        sub al,0x4
        jnz short $+5
        jmp L137
L40:
        jmp L1F5
L43:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x17
        jmp short $+62
        nop
L6D:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+20
        mov ax,0x18
L84:
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_3
L8E:
        add sp,0x4
        jmp short $+36
L93:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x19
LA8:
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
LB5:
        mov ax,0x1
        jmp L1F7
LBB:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x14
        jmp short $-78
        nop
LD5:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x15
        jmp short $-104
        nop
LEF:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x16
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov ax,0x11e
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        jmp L8E
L131:
        mov ax,0x1c
        jmp L84
L137:
        mov ax,0x10
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0xb0
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp LB5
L15E:
        mov ax,0x11
        jmp L84
        nop
L165:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x12
        jmp L84
L17F:
        mov ax,0xb0
        push ax
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
        mov ax,0x13
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x2
        jmp LB5
        nop
L1C3:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1a
        jmp LA8
L1EF:
        mov ax,0x1b
        jmp L84
L1F5:
        xor ax,ax
L1F7:
    }
}
