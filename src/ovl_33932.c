extern char __near mb6A16;
extern int __near mn6A10;
extern char __near mb0316;
void far helper_0(void);
void far helper_1(void);
int far ovl_33932(int a)
{
    _asm {
        sub sp,0x2
        mov al,mb6A16
        sub ah,ah
        mov [bp-0x2],ax
        mov ax,0x1
        push ax
        mov ax,0x7e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+30
        mov ax,0x7e
        push ax
        call far ptr helper_1
        add sp,0x2
        cmp ax,0x13e
        jnz short $+7
        mov ax,0x1
        jmp short $+5
L35:
        mov ax,0x2
L38:
        add [bp-0x2],ax
L3B:
        cmp word ptr [bp-0x2],0x2
        jnl short $+14
        mov word ptr mn6A10,0x4c0
        mov ax,0xd
        jmp short $+17
        nop
L4D:
        mov byte ptr mb0316,0x0
        mov word ptr mn6A10,0x4c1
        mov ax,0xe
L5B:
        mov dx,0xf035
    }
}
