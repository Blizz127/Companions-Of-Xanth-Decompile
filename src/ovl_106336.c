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
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
void far helper_10(void);
int far ovl_106336(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L319
L0E:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L301
L19:
        jna short $+5
        jmp L319
L1E:
        cmp al,0x38
        jnz short $+5
        jmp L121
L25:
        ja short $+16
        sub al,0xf
        jz short $+30
        sub al,0x4
        jnz short $+5
        jmp LC1
L32:
        jmp L319
L35:
        sub al,0x40
        jnz short $+5
        jmp L1D3
L3C:
        sub al,0x4
        jnz short $+5
        jmp L29D
L43:
        jmp L319
        nop
L47:
        mov ax,0x8
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+10
        mov ax,0x2510
        mov dx,ds
        jmp short $+6
        nop
L5F:
        xor ax,ax
        cwd
L62:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x21
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x75
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+18
        mov ax,0x116
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_3
        add sp,0x4
L9E:
        xor ax,ax
        push ax
LA1:
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_4
        add sp,0x6
        mov ax,0x8
        push ax
        call far ptr helper_5
        add sp,0x2
LBA:
        mov ax,0x1
        jmp L31B
        nop
LC1:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x250c
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x2
        sub ax,0x136
        jz short $+14
        dec ax
        jz short $+17
        dec ax
        jz short $+20
        dec ax
        jz short $+35
        jmp short $-64
        nop
LFD:
        mov ax,0x17
        jmp short $+12
        nop
L103:
        mov ax,0x18
        jmp short $+6
        nop
L109:
        mov ax,0x19
L10C:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-95
L11B:
        mov ax,0x1a
        jmp short $-18
        nop
L121:
        cmp word ptr mn6A02,0x75
        jz short $+25
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x40
L133:
        push ax
        call far ptr helper_8
        add sp,0x6
        jmp L31B
L13F:
        mov ax,0x75
        push ax
        mov ax,0x78
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+44
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x75
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
        jmp L262
L17D:
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x2
        cmp ax,0x136
        jz short $+27
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x1f
        jmp L2C9
        nop
L1A7:
        mov ax,0x75
        push ax
        mov cx,0x2
        push cx
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x20
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        push ax
        mov ax,0x75
        jmp LA1
L1D3:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+44
        mov ax,0x75
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        jmp short $+84
        nop
L211:
        cmp word ptr mn6A02,0x9b
        jnz short $+16
        mov ax,0x9b
        push ax
        push word ptr mn6A04
        mov ax,0x38
        jmp L133
L227:
        mov ax,0xb
        push ax
        push word ptr mn6A02
        call far ptr helper_9
        add sp,0x4
        or ax,ax
        jz short $+58
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x23
L262:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp LBA
        nop
L273:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x24
        jmp short $-56
        nop
L29D:
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x6
        or ax,ax
        jz short $+39
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
L2C9:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp LBA
L2D9:
        mov ax,0x75
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+16
        xor ax,ax
        push ax
        mov ax,0x75
        push ax
        mov ax,0x10
        jmp L133
        nop
L2FB:
        mov ax,0x1c
        jmp L10C
L301:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        jmp short $-77
        nop
L319:
        xor ax,ax
L31B:
    }
}
