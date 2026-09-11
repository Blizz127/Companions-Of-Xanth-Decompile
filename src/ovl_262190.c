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
int far ovl_262190(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp LE7
L12:
        jmp L253
L15:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L253
L20:
        cmp word ptr mn6A04,0x149
        jz short $+115
        cmp word ptr mn6A04,0x14a
        jz short $+107
        cmp word ptr mn6A04,0x14b
        jz short $+99
        cmp word ptr mn6A04,0x14c
        jz short $+91
        cmp word ptr mn6A04,0x14d
        jz short $+83
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+39
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x29
L71:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $+99
        nop
L81:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2a
        jmp short $-37
        nop
L99:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x28
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x6
LE1:
        mov ax,0x1
        jmp L255
LE7:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L23D
LF2:
        jna short $+5
        jmp L253
LF7:
        sub al,0x8
        jz short $+20
        sub al,0x4
        jz short $+40
        sub al,0x7
        jz short $+54
        sub al,0x19
        jnz short $+5
        jmp L225
L10A:
        jmp L253
L10D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x26
        jmp L71
L125:
        mov ax,0x27
L128:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp short $-84
L137:
        call far ptr helper_4
        mov [bp-0x4],ax
        mov ax,0x142
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x21
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L21F
L18A:
        push word ptr [bp-0x4]
        call far ptr helper_6
        add sp,0x2
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov word ptr [bp-0x6],0x0
        mov word ptr [bp-0x8],0x3498
L1B1:
        push word ptr mn6A04
        mov bx,[bp-0x8]
        push word ptr [bx]
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+76
        mov bx,[bp-0x8]
        push word ptr [bx]
        call far ptr helper_7
        add sp,0x2
        cbw
        push ax
        mov ax,0x352b
        push ds
        push ax
        call far ptr helper_2
        add sp,0x6
        mov ax,[bp-0x4]
        inc word ptr [bp-0x6]
        cmp [bp-0x6],ax
        jnz short $+12
        mov ax,0x23
        mov dx,0xf028
        push dx
        jmp short $+19
        nop
L1F7:
        sub ax,[bp-0x6]
        dec ax
        jnz short $+8
        mov ax,0x3530
        jmp short $+6
        nop
L203:
        mov ax,0x3536
L206:
        push ds
L207:
        push ax
        call far ptr helper_2
        add sp,0x4
L210:
        add word ptr [bp-0x8],0x2
        cmp word ptr [bp-0x8],0x34a2
        jc short $-104
        jmp LE1
        nop
L21F:
        mov ax,0x24
        jmp L128
L225:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x25
        jmp L71
L23D:
        xor ax,ax
        push ax
        mov ax,0x13f
        push ax
        push word ptr mn6A06
        call far ptr helper_8
        add sp,0x6
        jmp short $+5
        nop
L253:
        xor ax,ax
L255:
    }
}
