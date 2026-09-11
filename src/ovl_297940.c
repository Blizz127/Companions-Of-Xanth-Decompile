extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_297940(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp L135
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L135
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
        mov ax,0xb
L40:
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L4C:
        mov ax,0x1
        jmp L137
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LE5
L5E:
        jna short $+5
        jmp L135
L63:
        cmp al,0x2c
        jz short $+28
        ja short $+14
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+24
        jmp L135
        nop
L75:
        sub al,0x38
        jz short $+72
        sub al,0xc
        jz short $+68
        jmp L135
        nop
L81:
        mov ax,0x8
        jmp L10C
L87:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x5
        jmp short $+5
L9F:
        mov ax,0x6
LA2:
        mov dx,0xf046
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x4
        jmp short $-124
        nop
LBF:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x7
        mov dx,0xf046
        push dx
LD8:
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L4C
        nop
LE5:
        mov ax,0x9
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x193
        push ax
        mov ax,0xce
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+22
        mov ax,0xa
L10C:
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L4C
        nop
L11D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x38fb
        push ds
        jmp short $-91
L135:
        xor ax,ax
L137:
    }
}
