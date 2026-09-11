extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_248537(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp LEB
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LEB
L1A:
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
        mov ax,0x13
L40:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp LED
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+122
        jna short $+5
        jmp LEB
L60:
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+19
        sub al,0x19
        jz short $+9
        sub al,0xc
        jz short $+17
        jmp short $+123
        nop
L73:
        mov ax,0xf
        jmp short $-54
        nop
L79:
        mov ax,0xe
        jmp short $-60
        nop
L7F:
        cmp word ptr mn6A02,0x126
        jnz short $+54
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x10
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-110
        nop
LBB:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x11
        jmp L40
        nop
LD3:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x12
        jmp L40
        nop
LEB:
        xor ax,ax
LED:
    }
}
