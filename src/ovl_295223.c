extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb036B;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far ovl_295223(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+40
        jmp L1B7
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L1B7
L1E:
        mov ax,0xb
L21:
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_0
L2B:
        add sp,0x4
L2E:
        mov ax,0x1
        jmp L1B9
        nop
L35:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1B1
L40:
        jna short $+5
        jmp L1B7
L45:
        cmp al,0x21
        jnz short $+5
        jmp LCD
L4C:
        ja short $+15
        sub al,0x8
        jz short $+29
        sub al,0xb
        jz short $+75
        jmp L1B7
        nop
        nop
L5B:
        sub al,0x2c
        jnz short $+5
        jmp LE3
L62:
        sub al,0x18
        jnz short $+5
        jmp L199
L69:
        jmp L1B7
        nop
L6D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x8
        jmp short $+118
        nop
L99:
        mov ax,0x9
        jmp short $-123
        nop
L9F:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x4
        mov dx,0xf02b
        jmp short $+7
LBB:
        mov ax,0x38e0
        mov dx,ds
LC0:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x3
        jmp short $+65
LCD:
        xor ax,ax
        push ax
        mov ax,0x18e
        push ax
        push word ptr mn6A06
        call far ptr helper_3
        add sp,0x6
        jmp L1B9
LE3:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+40
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
L10C:
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L2E
        nop
L11D:
        mov ax,0x7
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        call far ptr helper_5
        mov ax,0x1f40
        push ax
        call far ptr helper_6
        add sp,0x2
        mov ax,0xa
        push ax
        mov ax,0x192
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+11
        mov ax,0x5a1c
        push ax
        mov ax,0x257
        jmp short $+18
L16B:
        mov ax,0x5a1c
        push ax
        cmp byte ptr mb036B,0x1
        sbb ax,ax
        and al,0xfd
        add ax,0x250
L17B:
        push ax
        call far ptr helper_7
        add sp,0x4
        mov byte ptr mb036B,0x1
        mov ax,0x3
        push ax
        mov ax,0x23
        push ax
        call far ptr helper_8
        jmp L2B
L199:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x5
        jmp L10C
L1B1:
        mov ax,0xa
        jmp L21
L1B7:
        xor ax,ax
L1B9:
    }
}
