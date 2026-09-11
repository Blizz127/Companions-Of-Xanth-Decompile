extern int __near mn6A06;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
int far ovl_160668(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+111
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+65
        ja short $+101
        sub al,0x13
        jz short $+9
        sub al,0x6
        jz short $+49
        jmp short $+91
        nop
L1D:
        mov ax,0x24
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        cmp word ptr mn0256,0x1aa
        jnz short $+17
        mov ax,0x25
L37:
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_0
L41:
        mov sp,bp
L43:
        mov ax,0x1
        jmp short $+49
        nop
L49:
        mov ax,0x27
        jmp short $-21
        nop
L4F:
        mov ax,mn0256
        sub ax,0x1aa
        jz short $+10
        sub ax,0x46
        jz short $+11
        jmp short $+25
        nop
L5F:
        mov ax,0x26
        jmp short $-43
        nop
L65:
        mov ax,0x5a0d
        push ax
        mov ax,0x260
        push ax
        call far ptr helper_1
        jmp short $-49
        nop
L75:
        xor ax,ax
L77:
    }
}
