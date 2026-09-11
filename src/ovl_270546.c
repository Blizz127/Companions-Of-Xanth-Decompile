extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_270546(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+57
        jmp L95
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+128
        mov ax,0x35e0
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x42
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xc
L30:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+88
        nop
        nop
L43:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+46
        ja short $+74
        cmp al,0x2c
        jz short $+34
        ja short $+12
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+18
        jmp short $+58
L5D:
        sub al,0x38
        jz short $+6
        sub al,0xc
        jnz short $+50
L65:
        mov ax,0x8
        jmp short $-56
        nop
L6B:
        mov ax,0x7
        jmp short $-62
        nop
L71:
        mov ax,0x9
        jmp short $-68
        nop
L77:
        push word ptr mn0256
        mov ax,0x12
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0xa
        jmp short $-93
L8F:
        mov ax,0xb
        jmp short $-98
        nop
L95:
        xor ax,ax
L97:
    }
}
