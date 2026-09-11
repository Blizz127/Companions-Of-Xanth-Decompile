extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_139745(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+73
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+59
        ja short $+63
        sub al,0x13
        jz short $+9
        sub al,0x31
        jz short $+43
        jmp short $+53
        nop
L1D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x19
L31:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+17
        nop
L43:
        mov ax,0x1a
        jmp short $-21
        nop
L49:
        mov ax,0x1b
        jmp short $-27
        nop
L4F:
        xor ax,ax
L51:
    }
}
