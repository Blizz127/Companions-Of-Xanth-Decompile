extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_74998(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+87
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+73
        ja short $+77
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+51
        sub al,0x19
        jz short $+53
        sub al,0x18
        jz short $+49
        jmp short $+59
        nop
L25:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x26
L39:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+23
        nop
L4B:
        mov ax,0x25
        jmp short $-21
        nop
L51:
        mov ax,0x27
        jmp short $-27
        nop
L57:
        mov ax,0x28
        jmp short $-33
        nop
L5D:
        xor ax,ax
L5F:
    }
}
