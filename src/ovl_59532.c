extern int __near mn6A04;
extern int __near mn0256;
extern int __near mn0258;
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
int far ovl_59532(int a)
{
    _asm {
        sub sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x6
        mov [bp-0x4],ax
        dec ax
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1a
        jmp short $+29
L33:
        cmp word ptr [bp-0x4],0x2
        jnz short $+40
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
L4E:
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L168
        nop
L5F:
        mov ax,0xc
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L149
L76:
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x2
        mov [bp-0x2],ax
        dec ax
        jnz short $+27
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        jmp L15E
        nop
LA1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1dc6
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
        cmp word ptr [bp-0x2],0x0
        jz short $+40
        mov ax,mn0256
        cmp [bp-0x2],ax
        jz short $+32
        push word ptr [bp-0x2]
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1dd1
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
LEC:
        mov ax,0x2e
        push ax
        call far ptr helper_5
        add sp,0x2
        xor ax,ax
        push ax
        push word ptr mn0258
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x2
        push ax
        call far ptr helper_8
        add sp,0x6
        xor ax,ax
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        mov ax,0x5
        push ax
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x4
        jmp short $+34
        nop
L149:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
L15E:
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_2
L168:
        mov ax,0x1
    }
}
