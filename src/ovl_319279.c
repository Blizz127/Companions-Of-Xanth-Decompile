extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_319279(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LDD
L0F:
        jmp L15F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x10
        jz short $+5
        jmp L15F
L23:
        cmp word ptr mn6A04,0x1c3
        jz short $+44
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
        mov ax,0x10
        jmp L115
        nop
L55:
        mov ax,0x1ce
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+61
        mov ax,0x1d1
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
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
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        jmp short $+117
        nop
LA3:
        mov ax,0x12
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0xf
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1ce
        push ax
        push word ptr mn6A04
        call far ptr helper_4
LD4:
        mov sp,bp
        mov ax,0x1
        jmp L161
        nop
LDD:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+100
        ja short $+122
        cmp al,0x2c
        jz short $+24
        ja short $+14
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+46
        jmp short $+106
        nop
        nop
LF9:
        sub al,0x38
        jz short $+6
        sub al,0xc
        jnz short $+96
L101:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xe
L115:
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_2
        jmp short $-75
L121:
        mov ax,0x1ce
        push ax
        mov ax,0x1c3
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+11
        mov ax,0xd
        mov dx,0xf04a
        jmp short $+6
        nop
L13D:
        xor ax,ax
        cwd
L140:
        push dx
        push ax
        mov ax,0xc
        jmp short $-48
L147:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        jmp short $-71
        nop
L15F:
        xor ax,ax
L161:
    }
}
