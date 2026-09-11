extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_154216(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LCB
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LC5
L16:
        jna short $+5
        jmp LCB
L1B:
        cmp al,0x29
        jnz short $+5
        jmp LB3
L22:
        ja short $+13
        sub al,0x8
        jz short $+27
        sub al,0xb
        jz short $+45
        jmp LCB
L2F:
        sub al,0x2c
        jnz short $+5
        jmp LB9
L36:
        sub al,0x18
        jnz short $+5
        jmp LBF
L3D:
        jmp LCB
        nop
L41:
        mov ax,0x2b
L44:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+122
        nop
        nop
L57:
        mov ax,mn0256
        cmp ax,0x14f
        jz short $+64
        jg short $+34
        sub ax,0x63
        jz short $+45
        sub ax,0x5b
        jz short $+46
L6B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x27
        jmp short $-59
L81:
        sub ax,0x160
        jz short $+25
        dec ax
        dec ax
        jz short $+21
        sub ax,0x4
        jz short $+16
        jmp short $-36
L91:
        mov ax,0x24
        jmp short $-80
        nop
L97:
        mov ax,0x25
        jmp short $-86
        nop
L9D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x26
        jmp short $-109
LB3:
        mov ax,0x28
        jmp short $-114
        nop
LB9:
        mov ax,0x2c
        jmp short $-120
        nop
LBF:
        mov ax,0x2a
        jmp L44
LC5:
        mov ax,0x29
        jmp L44
LCB:
        xor ax,ax
LCD:
    }
}
