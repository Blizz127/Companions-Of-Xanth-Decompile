extern int __near mn6A0E;
extern int __near mn5D94;
extern int __near mn5D92;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
int far ovl_9740(int a)
{
    _asm {
        sub sp,0x2
        mov ax,mn6A0E
        mov [bp-0x2],ax
        mov word ptr mn5D94,0x0
        mov word ptr mn5D92,0x270f
        mov ax,0x1
        push ax
        mov ax,0x496
        mov dx,0x30cb
        push dx
        push ax
        push word ptr mn0256
        call far ptr helper_0
        add sp,0x8
        mov ax,mn6A0E
        cmp mn5D94,ax
        jz short $+42
        mov ax,mn5D94
        mov mn6A0E,ax
        cmp word ptr [bp+0x6],0x0
        jz short $+30
        cmp word ptr [bp-0x2],0x0
        jnz short $+7
        mov ax,0x177c
        jmp short $+12
L4D:
        cmp word ptr mn6A0E,0x0
        jnz short $+12
        mov ax,0x1788
L57:
        push ds
        push ax
        call far ptr helper_1
L5E:
        mov ax,mn6A0E
    }
}
