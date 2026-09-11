extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_155179(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+122
        jmp L14F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L14F
L1E:
        cmp word ptr mn0256,0x98
        jnz short $+9
        mov ax,0x2aca
        mov dx,ds
        jmp short $+8
L2D:
        mov ax,0x4c
        mov dx,0xf008
L33:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x4
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
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
        mov ax,0x4b
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x14
L81:
        mov ax,0x1
        jmp L151
L87:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L137
L92:
        jna short $+5
        jmp L14F
L97:
        sub al,0x7
        jz short $+18
        sub al,0xa
        jz short $+52
        sub al,0x2
        jz short $+70
        sub al,0x31
        jz short $+126
        jmp L14F
        nop
LAB:
        cmp word ptr mn0256,0x9c
        jnz short $+8
        mov ax,0x2ac5
        jmp short $+6
        nop
LB9:
        mov ax,0x2ac8
LBC:
        push ds
        push ax
        mov ax,0x4a
LC1:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-77
        nop
LD1:
        xor ax,ax
        push ax
        mov ax,0x1b
        push ax
        push word ptr mn6A06
        call far ptr helper_2
        add sp,0x6
        jmp short $+109
        nop
LE7:
        cmp word ptr mn0256,0x98
        jnz short $+8
        mov ax,0x46
        jmp short $+6
        nop
LF5:
        mov ax,0x47
LF8:
        mov dx,0xf008
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x45
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp L81
        nop
L123:
        mov ax,0x48
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L81
        nop
L137:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x49
        jmp LC1
L14F:
        xor ax,ax
L151:
    }
}
