extern char __near mb0358;
char g;
void far helper_mkfp(void);
int far if15_277752(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+42
        cmp byte ptr mb0358,0x0
        jz short $+22
        mov ax,0x7
        mov dx,0xf03d
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        xor ax,ax
        jmp short $+19
        nop
L21:
        mov ax,0x8
        mov dx,0xf03d
        push dx
        push ax
        call far ptr helper_mkfp
L2E:
        mov ax,0x169
L31:
    }
}
