extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_145752(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+122
        jmp L13D
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L13D
L1E:
        cmp word ptr mn6A04,0xb1
        jnz short $+59
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+39
        mov ax,0xe
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0xb0
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x6
        jmp short $+36
L5F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
L74:
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L81:
        mov ax,0x1
        jmp L13F
L87:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L129
L92:
        jna short $+5
        jmp L13D
L97:
        sub al,0x13
        jz short $+18
        sub al,0x19
        jz short $+92
        sub al,0xc
        jz short $+112
        sub al,0xc
        jz short $+108
        jmp L13D
        nop
LAB:
        push word ptr mn6A04
        mov ax,0xb1
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0xa
        mov dx,0xf013
        jmp short $+7
LC7:
        mov ax,0x29da
        mov dx,ds
LCC:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x9
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp short $-117
        nop
LF9:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0xc
        jmp L74
L111:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        jmp L74
L129:
        mov ax,0xd
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L81
        nop
L13D:
        xor ax,ax
L13F:
    }
}
