extern int __near mn6A06;
extern int __near mn02BE;
extern int __near mn02A8;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_193785(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L169
L0E:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L163
L19:
        jna short $+5
        jmp L169
L1E:
        cmp al,0x2c
        jz short $+47
        ja short $+21
        sub al,0x8
        jz short $+41
        sub al,0x6
        jz short $+59
        sub al,0x5
        jnz short $+5
        jmp LE3
L33:
        jmp L169
        nop
L37:
        sub al,0x33
        jnz short $+5
        jmp LE9
L3E:
        sub al,0x5
        jnz short $+5
        jmp LE9
L45:
        sub al,0xc
        jnz short $+5
        jmp L129
L4C:
        jmp L169
L4F:
        mov ax,0x2d
L52:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
L5F:
        mov ax,0x1
        jmp L16B
L65:
        inc word ptr mn02BE
        cmp word ptr mn02BE,0x1
        jng short $+9
        mov ax,0x30ce
        mov dx,ds
        jmp short $+5
L77:
        xor ax,ax
        cwd
L7A:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov bx,mn02BE
        add bx,bx
        add bx,bx
        push word ptr [bx+0x30bc]
        push word ptr [bx+0x30ba]
        push dx
        push ax
        mov ax,0x30
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        cmp word ptr mn02BE,0x4
        jnz short $-72
        mov ax,0xb
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x1c
        push ax
        call far ptr helper_3
        add sp,0x2
        mov word ptr mn02A8,0xe
        mov ax,0x5a
        push ax
        call far ptr helper_4
        add sp,0x2
        jmp L5F
        nop
LE3:
        mov ax,0x2b
        jmp L52
LE9:
        cmp word ptr mn6A02,0xd9
        jz short $+122
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x2f
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        jmp L5F
        nop
L129:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        or ax,ax
        jz short $+46
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L5F
        nop
L163:
        mov ax,0x2e
        jmp L52
L169:
        xor ax,ax
L16B:
    }
}
