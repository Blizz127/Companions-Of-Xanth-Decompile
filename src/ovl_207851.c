extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_207851(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L107
L0F:
        jmp L16D
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L16D
L1E:
        cmp word ptr mn6A04,0x123
        jnz short $+75
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
        mov ax,0x51
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        jmp L101
        nop
L6F:
        cmp word ptr mn6A04,0x122
        jz short $+106
        cmp word ptr mn6A04,0x121
        jz short $+98
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x53
        jmp short $+78
        nop
LA9:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x54
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp short $+36
LDF:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x52
LF4:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L101:
        mov ax,0x1
        jmp short $+107
        nop
L107:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+72
        ja short $+94
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+24
        sub al,0x19
        jnz short $+82
L11D:
        mov ax,0x4f
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-44
L12F:
        push word ptr mn6A04
        mov ax,0x123
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x4e
        mov dx,0xf025
        jmp short $+5
L14B:
        xor ax,ax
        cwd
L14E:
        push dx
        push ax
        mov ax,0x4d
        jmp short $-95
L155:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x50
        jmp short $-118
        nop
L16D:
        xor ax,ax
L16F:
    }
}
