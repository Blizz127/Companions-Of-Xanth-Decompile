extern int __near mn5D92;
extern int __near mn5D94;
void far helper_0(void);
int far ovl_9686(int a)
{
    _asm {
        mov ax,0x9
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+31
        mov ax,mn5D92
        cmp [bp+0x8],ax
        jnl short $+23
        mov ax,[bp+0x6]
        mov mn5D94,ax
        mov ax,[bp+0x8]
        mov mn5D92,ax
        or ax,ax
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L2F:
        xor ax,ax
L31:
    }
}
