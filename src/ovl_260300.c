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
int far ovl_260300(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L95
L0F:
        jmp L1A7
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L1A7
L1E:
        cmp word ptr mn6A04,0x149
        jz short $+91
        cmp word ptr mn6A04,0x14a
        jz short $+83
        cmp word ptr mn6A04,0x14b
        jz short $+75
        cmp word ptr mn6A04,0x14c
        jz short $+67
        cmp word ptr mn6A04,0x14d
        jz short $+59
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
        mov ax,0xe
L6C:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L78:
        mov ax,0x1
        jmp L1A9
        nop
L7F:
        mov ax,0x143
        push ax
        push word ptr mn6A04
L87:
        push word ptr mn6A06
        call far ptr helper_2
        mov sp,bp
        jmp L1A9
L95:
        mov ax,mn6A06
        cmp ax,0x13
        jz short $+58
        ja short $+10
        sub ax,0x8
        jz short $+29
        jmp L1A7
LA7:
        sub ax,0x2c
        jz short $+21
        sub ax,0x18
        jnc short $+5
        jmp L1A7
LB4:
        sub ax,0x1
        ja short $+5
        jmp L19D
LBC:
        jmp L1A7
LBF:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xd
        jmp short $-103
LD5:
        mov ax,0x143
        push ax
        mov cx,0x12
        push cx
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        push ax
        mov ax,0x143
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+27
        call far ptr helper_4
        push ax
        call far ptr helper_5
        mov sp,bp
        push dx
        push ax
        mov ax,0xb
        mov dx,0xf028
        push dx
        jmp short $+7
        nop
L121:
        mov ax,0x34e0
        push ds
L125:
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x144
        push ax
        mov cx,0x12
        push cx
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x34ea
        push ds
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xe
        push ax
        mov ax,0x144
        push ax
        call far ptr helper_6
        mov sp,bp
        or ax,ax
        jz short $+38
        mov ax,0x34ee
        push ds
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        call far ptr helper_7
        mov sp,bp
        or ax,ax
        jz short $+25
        mov ax,0xc
        mov dx,0xf028
        push dx
        jmp short $+7
        nop
L181:
        mov ax,0x34f3
        push ds
L185:
        push ax
        call far ptr helper_1
        add sp,0x4
L18E:
        mov ax,0x2e
        push ax
        call far ptr helper_8
        add sp,0x2
        jmp L78
L19D:
        xor ax,ax
        push ax
        mov ax,0x13f
        push ax
        jmp L87
L1A7:
        xor ax,ax
L1A9:
    }
}
