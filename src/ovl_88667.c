extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_88667(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+79
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+65
        ja short $+69
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+27
        sub al,0x19
        jnz short $+57
L1E:
        mov ax,0x37
L21:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+39
        nop
L33:
        mov ax,0x22f7
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x36
        jmp short $-43
        nop
L4F:
        mov ax,0x38
        jmp short $-49
        nop
L55:
        xor ax,ax
L57:
    }
}
