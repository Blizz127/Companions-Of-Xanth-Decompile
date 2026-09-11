extern char __near mb030D;
char g;
void far helper(void);
void far helper2(void);
int far if15_149383(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+33
        mov ax,0x1
        push ax
        mov ax,0x8b
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jz short $+93
        cmp byte ptr mb030D,0x0
        jz short $+86
L20:
        mov ax,0xbe
        jmp short $+89
L25:
        cmp byte ptr mb030D,0x0
        jz short $+79
        mov ax,0x1
        push ax
        mov ax,0x8b
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jz short $+60
        mov ax,0x1
        push ax
        mov ax,0xa5
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jnz short $+21
        mov ax,0x1
        push ax
        mov ax,0xa4
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jz short $+-67
L65:
        mov ax,0x64e
        push ax
        mov ax,0x35d
        push ax
        call far ptr helper2
        mov sp,bp
L74:
        xor ax,ax
        jmp short $+6
        nop
L79:
        mov ax,0xffff
L7C:
    }
}
