extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_146632(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+73
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+59
        ja short $+63
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+43
        sub al,0x19
        jnz short $+51
L1E:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1f
L32:
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L43:
        mov ax,0x1e
        jmp short $-20
        nop
L49:
        mov ax,0x20
        jmp short $-26
        nop
L4F:
        xor ax,ax
L51:
    }
}
