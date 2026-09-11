extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn5ADA;
extern int __near mn02C0;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_194155(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L10B
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LF3
L16:
        jna short $+5
        jmp L10B
L1B:
        cmp al,0x20
        jz short $+104
        ja short $+14
        sub al,0x8
        jz short $+32
        sub al,0xb
        jz short $+66
        jmp L10B
        nop
L2D:
        sub al,0x2c
        jz short $+20
        sub al,0xc
        jnz short $+5
        jmp LC3
L38:
        sub al,0xc
        jnz short $+5
        jmp LED
L3F:
        jmp L10B
        nop
L43:
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x36
L57:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L63:
        mov ax,0x1
        jmp L10D
L69:
        mov es, mn5ADA
        mov bx,mn02C0
        add bx,bx
        add bx,bx
        push word ptr es:[bx+0x86]
        push word ptr es:[bx+0x84]
        mov ax,0x34
        jmp short $-43
        nop
L85:
        cmp word ptr mn02C0,0x0
        jz short $+21
        mov ax,0x38
L8F:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-57
        nop
L9F:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x39
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-94
LC3:
        mov ax,0xd9
        push ax
        mov ax,0xfe
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+54
        push word ptr mn6A02
        mov ax,0xd9
        push ax
        push word ptr mn6A06
        call far ptr helper_3
        add sp,0x6
        jmp short $+34
LED:
        mov ax,0x35
        jmp short $-97
        nop
LF3:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x37
        jmp L57
L10B:
        xor ax,ax
L10D:
    }
}
