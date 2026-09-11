extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_305240(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+111
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+81
        ja short $+101
        cmp al,0x2c
        jz short $+25
        ja short $+13
        sub al,0x8
        jz short $+19
        sub al,0xb
        jz short $+53
        jmp short $+85
        nop
L23:
        sub al,0x38
        jz short $+52
        sub al,0xc
        jz short $+48
        jmp short $+74
L2D:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x40
L41:
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+39
        nop
L53:
        mov ax,0x3d
        jmp short $-21
        nop
L59:
        mov ax,0x3f
        jmp short $-27
        nop
L5F:
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x41
        jmp short $-50
L75:
        xor ax,ax
L77:
    }
}
