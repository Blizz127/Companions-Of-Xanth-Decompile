extern char __near mb036C;
void far helper_0(void);
void far helper_1(void);
int far ovl_298258(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+51
        cmp byte ptr mb036C,0x0
        jz short $+24
        mov ax,0x2
        push ax
        push word ptr [bp+0x8]
        call far ptr helper_0
        mov sp,bp
        mov ax,0x3906
L1E:
        mov dx,ds
        jmp short $+26
        nop
L23:
        mov ax,0x2
        push ax
        push word ptr [bp+0x8]
        call far ptr helper_1
        mov sp,bp
        mov ax,0x390e
        jmp short $-22
        nop
L37:
        xor ax,ax
        cwd
L3A:
    }
}
