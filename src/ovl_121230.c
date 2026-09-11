extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_121230(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+79
        jmp LC3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC3
L1A:
        mov ax,mn6A04
        sub ax,0x8f
        jz short $+23
        mov ax,0x12
L25:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
L2F:
        mov sp,bp
        mov ax,0x1
        jmp LC5
L37:
        mov ax,0x11
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_1
        jmp short $-40
L59:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+94
        ja short $+98
        cmp al,0x1c
        jz short $+56
        ja short $+12
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+24
        jmp short $+82
L73:
        sub al,0x2c
        jz short $+12
        dec al
        jz short $+56
        sub al,0x17
        jz short $+58
        jmp short $+68
L81:
        mov ax,0xc
        jmp short $-95
        nop
L87:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp short $-118
L9D:
        cmp word ptr mn0256,0x8c
        jnz short $+8
        mov ax,0xe
        jmp L25
LAB:
        mov ax,0xf
        jmp L25
LB1:
        mov ax,0x10
        jmp L25
LB7:
        mov ax,0xb
        jmp L25
LBD:
        mov ax,0xd
        jmp L25
LC3:
        xor ax,ax
LC5:
    }
}
