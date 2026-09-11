extern char __near mb6E5C;
char g;
void far helper_mkfp(void);
int far if15_103898(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+57
        cmp byte ptr mb6E5C,0x8
        jnz short $+8
        mov ax,0x24ad
        jmp short $+6
        nop
L13:
        mov ax,0x24b7
L16:
        push ds
        push ax
        cmp byte ptr mb6E5C,0x8
        jnz short $+8
        mov ax,0x24c1
        jmp short $+6
        nop
L25:
        mov ax,0x24c4
L28:
        push ds
        push ax
        mov ax,0x4d
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        xor ax,ax
        jmp short $+5
L3D:
        mov ax,0x59
L40:
    }
}
