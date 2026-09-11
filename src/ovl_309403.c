extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_309403(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp short $+87
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+78
        mov ax,0x1b5
        push ax
        push word ptr mn6A04
L1F:
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp short $+59
        nop
L2D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+16
        ja short $+46
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+16
        sub al,0x19
        jnz short $+34
L43:
        xor ax,ax
        push ax
        mov ax,0x1b2
        push ax
        jmp short $-43
        nop
L4D:
        mov ax,0x1b
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
        jmp short $+5
        nop
L63:
        xor ax,ax
L65:
    }
}
