extern int __near mn6A06;
extern int __near mn02C6;
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
int far ovl_104960(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+41
        dec ax
        dec ax
        jz short $+5
        jmp L1F7
L0F:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1A7
L1A:
        ja short $+21
        sub al,0x13
        jz short $+31
        sub al,0x1b
        jz short $+65
        sub al,0x11
        jnz short $+5
        jmp L18F
L2B:
        sub al,0x5
        jz short $+54
L2F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+5
        jmp L1AD
L3A:
        jmp L1F7
L3D:
        mov ax,0x6b
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        xor ax,ax
L50:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5C:
        mov ax,0x1
        jmp L1F9
        nop
L63:
        mov ax,0x1
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L143
L79:
        mov ax,0x75
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+25
        mov ax,0x75
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1
        jmp short $-80
        nop
LA3:
        mov ax,0x75
        push ax
        mov ax,0x78
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+20
        mov ax,0x2
LBA:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-107
LC9:
        mov ax,0x1
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x4
        mov dx,0xf030
        jmp short $+5
LE5:
        xor ax,ax
        cwd
LE8:
        push dx
        push ax
        mov ax,0x3
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        push ax
        mov ax,0x75
        push ax
        mov cx,0x76
        push cx
        call far ptr helper_4
        add sp,0x6
        mov ax,0x117
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_5
        add sp,0x4
        mov ax,0x136
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_5
        add sp,0x4
        mov ax,0x8
        push ax
        call far ptr helper_6
        add sp,0x2
        mov word ptr mn02C6,0x0
        jmp L5C
L143:
        mov ax,0x75
        push ax
        mov cx,0x1
        push cx
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x5
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x75
        push dx
        call far ptr helper_4
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_7
        add sp,0x6
        jmp L5C
        nop
L18F:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
        jmp L50
L1A7:
        mov ax,0x7
        jmp LBA
L1AD:
        mov ax,mn6A04
        sub ax,0x75
        jl short $+7
        jo short $+5
        dec ax
        jng short $+57
L1BA:
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
        mov ax,0x9
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp L5C
L1F1:
        mov ax,0x8
        jmp LBA
L1F7:
        xor ax,ax
L1F9:
    }
}
