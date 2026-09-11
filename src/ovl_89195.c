extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_89195(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp LCB
L12:
        jmp L193
L15:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x9
        jz short $+5
        jmp L193
L25:
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+42
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x4f
L4E:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L5B:
        mov ax,0x1
        jmp L195
L61:
        cmp word ptr mn6A04,0x4d
        jz short $+5
        jmp L193
L6B:
        mov ax,0xe
        push ax
        mov ax,0x4d
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0x50
        jmp short $+26
        nop
L85:
        mov ax,0xa
        push ax
        push word ptr mn6A02
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+20
        mov ax,0x51
L9C:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
LA6:
        add sp,0x4
        jmp short $-78
LAB:
        mov ax,0x52
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A02
        call far ptr helper_4
        jmp short $-34
        nop
LCB:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L18D
LD6:
        jna short $+5
        jmp L193
LDB:
        sub al,0xf
        jz short $+16
        sub al,0x4
        jz short $+86
        sub al,0x2c
        jz short $+128
        sub al,0x5
        jmp L193
        nop
LED:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x22fb
        mov dx,ds
        jmp short $+6
        nop
L109:
        xor ax,ax
        cwd
L10C:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x4b
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x6
        jmp L5B
L137:
        mov ax,0x49
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L5B
L15E:
        mov ax,0x4a
        jmp L9C
        nop
L165:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x4d
        mov dx,0xf005
        jmp short $+5
L181:
        xor ax,ax
        cwd
L184:
        push dx
        push ax
        mov ax,0x4c
        jmp L4E
        nop
L18D:
        mov ax,0x4e
        jmp L9C
L193:
        xor ax,ax
L195:
    }
}
