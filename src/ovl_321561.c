extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_321561(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+99
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+85
        ja short $+89
        cmp al,0x2c
        jz short $+29
        ja short $+13
        sub al,0x8
        jz short $+23
        sub al,0xb
        jz short $+57
        jmp short $+73
        nop
L23:
        sub al,0x38
        jz short $+56
        sub al,0x2
        jz short $+46
        sub al,0xa
        jz short $+48
        jmp short $+58
L31:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x10
L45:
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+23
        nop
L57:
        mov ax,0xe
        jmp short $-21
        nop
L5D:
        mov ax,0xf
        jmp short $-27
        nop
L63:
        mov ax,0x11
        jmp short $-33
        nop
L69:
        xor ax,ax
L6B:
    }
}
