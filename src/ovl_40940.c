extern char __near mb6A12;
extern char __near mb6A13;
extern char __near mb6A14;
extern char __near mb6A15;
extern char __near mb6A16;
extern char __near mb6A17;
extern char __near mb6A18;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_40940(int a)
{
    _asm {
        mov ax,[bp+0x8]
        sub ax,0x3
        jz short $+13
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        jmp short $+72
L13:
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov cx,0xbd
        push cx
        call far ptr helper_0
        add sp,0x6
        mov ax,0xa
        push ax
        mov ax,0xbd
        push ax
        call far ptr helper_1
        add sp,0x4
        xor al,al
        mov mb6A12,al
        mov mb6A13,al
        mov mb6A14,al
        mov mb6A15,al
        mov mb6A16,al
        mov mb6A17,al
        mov mb6A18,al
        mov ax,0x1
        push ax
        mov ax,0x8
        push ax
        mov ax,0x8026
        push ax
L59:
        call far ptr helper_2
    }
}
