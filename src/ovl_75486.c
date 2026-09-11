extern char __near mb0325;
void far helper_0(void);
void far helper_1(void);
int far ovl_75486(void)
{
    _asm {
        mov byte ptr mb0325,0x1
        call far ptr helper_0
        mov cx,0xc
        cwd
        idiv cx
        inc dx
        push dx
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        retf
    }
}
