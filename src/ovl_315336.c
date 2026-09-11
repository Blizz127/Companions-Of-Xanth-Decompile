extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_315336(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+58
        jmp L161
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L161
L1E:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x29
L33:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L40:
        mov ax,0x1
        jmp L163
        nop
L47:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+60
        jna short $+5
        jmp L161
L54:
        cmp al,0x13
        jz short $+65
        ja short $+13
        sub al,0x7
        jz short $+21
        dec al
        jz short $+41
        jmp L161
L65:
        sub al,0x2c
        jz short $+34
        sub al,0x18
        jz short $+96
        jmp L161
        nop
L71:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x28
        jmp short $-83
        nop
L89:
        push word ptr mn6A04
        call far ptr helper_2
L92:
        add sp,0x2
        jmp short $-85
L97:
        cmp word ptr mn0256,0x1bd
        jnz short $+30
        mov ax,0xe
        push ax
        mov ax,0x1be
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+10
        mov word ptr [bp-0x2],0x3a61
        jmp short $+8
        nop
LBB:
        mov word ptr [bp-0x2],0x3a6d
LC0:
        push ds
        push word ptr [bp-0x2]
        mov ax,0x24
        jmp L33
        nop
LCB:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+22
        mov ax,0x25
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L40
        nop
LF3:
        mov ax,0x1ce
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x26
        jmp L33
L11F:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x27
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_5
        add sp,0x6
        push word ptr mn6A04
        call far ptr helper_6
        jmp L92
        nop
L161:
        xor ax,ax
L163:
    }
}
