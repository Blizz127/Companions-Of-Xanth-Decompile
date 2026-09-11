extern char __near mb6E5C;
char g;
void far helper_mkfp(void);
int far if15_255352(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0xf
        jnz short $+40
        cmp byte ptr mb6E5C,0x1
        jnz short $+7
        xor ax,ax
        cwd
        jmp short $+7
L15:
        mov ax,0x3490
        mov dx,ds
L1A:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x31
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_mkfp
L2F:
        mov ax,0x132
    }
}
