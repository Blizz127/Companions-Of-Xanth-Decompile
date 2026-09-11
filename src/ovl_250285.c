extern int __near mn6A06;
void far helper_0(void);
int far ovl_250285(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+91
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+82
        mov ax,0x36
L1A:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+64
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+48
        ja short $+52
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+20
        jmp short $+36
L45:
        sub al,0x38
        jz short $+20
        sub al,0xc
        jz short $+16
        jmp short $+26
L4F:
        mov ax,0x33
        jmp short $-56
        nop
L55:
        mov ax,0x32
        jmp short $-62
        nop
L5B:
        mov ax,0x34
        jmp short $-68
        nop
L61:
        mov ax,0x35
        jmp short $-74
        nop
L67:
        xor ax,ax
L69:
    }
}
