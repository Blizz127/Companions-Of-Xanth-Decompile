extern int __near mn0256;
extern char __near mb0322;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_70587(int a)
{
    _asm {
        sub sp,0x4
        call far ptr helper_0
        mov ax,0x1
        push ax
        mov ax,0x3e
        push ax
        mov ax,0x50
        push ax
        call far ptr helper_1
        mov ax,0x6
        add sp,ax
        push ax
        mov ax,0x50
        push ax
        call far ptr helper_2
        add sp,0x4
        cmp word ptr mn0256,0x33
        jnz short $+37
        mov ax,0xe
        push ax
        mov ax,0x34
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+17
        mov ax,0x40
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        jmp short $+53
L55:
        cmp word ptr mn0256,0x33
        jnz short $+7
        xor ax,ax
        cwd
        jmp short $+7
L61:
        mov ax,0x1eb7
        mov dx,ds
L66:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x41
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_4
        add sp,0x8
        mov ax,0x1ec5
        push ds
        push ax
        call far ptr helper_5
L88:
        mov ax,0x1
        mov mb0322,al
    }
}
