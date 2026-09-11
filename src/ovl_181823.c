extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb032C;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_181823(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LCF
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LC9
L16:
        jna short $+5
        jmp LCF
L1B:
        cmp al,0x2c
        jz short $+32
        ja short $+14
        sub al,0x8
        jz short $+26
        sub al,0xb
        jz short $+60
        jmp LCF
        nop
L2D:
        sub al,0x37
        jz short $+58
        dec al
        jz short $+128
        sub al,0xc
        jz short $+124
        jmp LCF
        nop
L3D:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x10
L51:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5D:
        mov ax,0x1
        jmp short $+113
        nop
L63:
        mov ax,0xe
        jmp short $-21
        nop
L69:
        mov ax,0x12
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xe
        push ax
        mov ax,0xd7
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+8
        mov ax,0x13
        jmp short $-61
        nop
L91:
        mov ax,0x14
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xbb8
        push ax
        call far ptr helper_3
        mov sp,bp
        mov byte ptr mb032C,0x1
        jmp short $-83
        nop
LB3:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xf
        jmp short $-118
LC9:
        mov ax,0x11
        jmp short $-123
        nop
LCF:
        xor ax,ax
LD1:
    }
}
