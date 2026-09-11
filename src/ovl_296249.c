extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_296249(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp L91
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+124
        mov ax,0x1d
L1A:
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_0
L24:
        mov sp,bp
        mov ax,0x1
        jmp short $+106
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+54
        ja short $+94
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+26
        jmp short $+78
L45:
        sub al,0x38
        jz short $+26
        sub al,0xc
        jz short $+22
        jmp short $+68
L4F:
        push word ptr mn6A04
        call far ptr helper_1
        jmp short $-52
        nop
L5B:
        mov ax,0x1a
        jmp short $-68
        nop
L61:
        mov ax,0x1b
        jmp short $-74
        nop
L67:
        mov ax,0x1c
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x5a01
        push ax
        mov ax,0x2c8
        push ax
        call far ptr helper_3
        jmp short $-106
        nop
L91:
        xor ax,ax
L93:
    }
}
