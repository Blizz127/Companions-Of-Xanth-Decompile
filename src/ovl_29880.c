extern char __near mb02F6;
extern int __near mn6A10;
void far helper_0(void);
int far ovl_29880(void)
{
    _asm {
        cmp byte ptr mb02F6,0x0
        jz short $+71
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x80b2
        push dx
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x2
        push cx
        mov cx,0x80b2
        push cx
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        xor ax,ax
        push ax
        mov ax,0x80b2
        push ax
        call far ptr helper_0
        add sp,0x6
        mov word ptr mn6A10,0x47c
        mov ax,0x5
        jmp short $+65
        nop
L4C:
        mov ax,0x1
        push ax
        push ax
        mov cx,0x80b2
        push cx
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        mov ax,0x80b2
        push ax
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov ax,0x80b2
        push ax
        call far ptr helper_0
        add sp,0x6
        mov word ptr mn6A10,0x47d
        mov ax,0x6
L8A:
        mov dx,0xf034
        retf
    }
}
