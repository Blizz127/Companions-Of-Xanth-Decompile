extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_200566(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+115
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+106
        mov ax,0x16
L1A:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+88
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+72
        ja short $+76
        sub al,0x8
        jz short $+14
        sub al,0x9
        jz short $+50
        sub al,0x2
        jz short $+52
        sub al,0x19
        jnz short $+60
L45:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        cmp word ptr mn6A06,0x2c
        jnz short $+8
        mov ax,0x317c
        jmp short $+6
        nop
L63:
        mov ax,0x3181
L66:
        push ds
        push ax
        mov ax,0x13
        jmp short $-81
L6D:
        mov ax,0x15
        jmp short $-86
        nop
L73:
        mov ax,0x12
        jmp short $-92
        nop
L79:
        mov ax,0x14
        jmp short $-98
        nop
L7F:
        xor ax,ax
L81:
    }
}
