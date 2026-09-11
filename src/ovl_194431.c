extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
extern char __near mb0329;
extern char __near mb033F;
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
int far ovl_194431(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L2D1
L0E:
        mov ax,mn6A06
        cmp ax,0x47
        jnz short $+5
        jmp L24F
L19:
        jna short $+5
        jmp L2D1
L1E:
        cmp al,0x2c
        jnz short $+5
        jmp L1C9
L25:
        ja short $+14
        sub al,0x13
        jz short $+34
        sub al,0x10
        jz short $+108
        jmp L2D1
        nop
L33:
        sub al,0x38
        jnz short $+5
        jmp L1E1
L3A:
        sub al,0x7
        jnz short $+5
        jmp L223
L41:
        sub al,0x6
        jnz short $+5
        jmp L23B
L48:
        jmp L2D1
L4B:
        mov ax,0x1b
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+10
        mov ax,0x3b
        mov dx,0xf021
        jmp short $+5
L63:
        xor ax,ax
        cwd
L66:
        push dx
        push ax
        mov ax,0x1b
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+7
        mov ax,0x30ef
        jmp short $+5
L7D:
        mov ax,0x30f1
L80:
        push ds
        push ax
        mov ax,0x3a
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L92:
        mov ax,0x1
        jmp L2D3
        nop
L99:
        mov ax,0x1b
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x40
        jmp short $+55
        nop
LC1:
        cmp word ptr mn0256,0xcd
        jz short $+62
        cmp word ptr mn0256,0xed
        jz short $+54
        cmp word ptr mn0256,0x102
        jnz short $+9
        cmp byte ptr mb0329,0x0
        jz short $+39
LE0:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x43
LF5:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-112
        nop
L105:
        mov ax,0x14f
        push ax
        mov ax,0xff
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x1
        push ax
        mov cx,0x1b
        push cx
        call far ptr helper_4
        add sp,0x4
        mov byte ptr mb033F,0x1
        cmp word ptr mn0256,0x102
        jnz short $+7
        mov ax,0x103
        jmp short $+5
L137:
        mov ax,0xcf
L13A:
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x41
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        mov ax,0x1
        push ax
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_5
        add sp,0x6
        mov ax,0x1388
        push ax
        call far ptr helper_6
        add sp,0x2
        cmp word ptr mn0256,0x102
        jz short $+5
        jmp L92
L193:
        mov ax,0x42
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
L1A3:
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_5
        add sp,0x6
        jmp L92
L1C9:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
        jmp LF5
L1E1:
        mov ax,0x1b
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jnz short $+38
        cmp word ptr mn6A02,0xcf
        jz short $+10
        cmp word ptr mn6A02,0x103
        jnz short $+22
L201:
        push ax
        push word ptr mn6A04
        mov ax,0x23
L209:
        push ax
        call far ptr helper_8
        add sp,0x6
        jmp L2D3
L215:
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x47
        jmp short $-23
        nop
L223:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x3f
        jmp LF5
L23B:
        mov ax,0x3d
L23E:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L92
        nop
L24F:
        cmp word ptr mn6A02,0x103
        jnz short $+118
        mov ax,0x1b
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+8
        xor ax,ax
        cwd
        jmp short $+8
        nop
L26D:
        mov ax,0x30f6
        mov dx,ds
L272:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x44
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        mov ax,0x1b
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+5
        jmp L1A3
L2B3:
        mov ax,0x1
        push ax
        mov ax,0x1b
        push ax
        call far ptr helper_4
        add sp,0x4
        mov byte ptr mb033F,0x1
        jmp L1A3
L2CB:
        mov ax,0x45
        jmp L23E
L2D1:
        xor ax,ax
L2D3:
    }
}
