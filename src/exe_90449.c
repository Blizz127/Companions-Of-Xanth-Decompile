extern int __near mn4D34;
extern int __near mn4D36;
extern int __near mn4D34;
extern int __near mn4D36;
void far helper_0(void);
int far exe_90449(int a)
{
    _asm {
        sub sp,0x10
        cmp word ptr mn4D34,0x0
        jz short $+37
        dec word ptr mn4D34
        mov word ptr [bp-0x2],0x3
        mov word ptr [bp-0x10],0xc00
        lea ax,[bp-0x10]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x21
        push ax
        call far ptr helper_0
        add sp,0xa
        jmp short $+88
lbl2D:
        cmp word ptr mn4D36,-1
        jnz short $+69
        mov byte ptr [bp-0xf],0x7
        lea ax,[bp-0x10]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x21
        push ax
        call far ptr helper_0
        add sp,0xa
        mov [bp-0x2],ax
        and word ptr [bp-0x2],0xff
        jnz short $+48
        mov byte ptr [bp-0xf],0x7
        lea ax,[bp-0x10]
        push ss
        push ax
        push ss
        push ax
        mov cx,0x21
        push cx
        call far ptr helper_0
        add sp,0xa
        mov al,[bp-0x10]
        mov ah,0x1
        mov [bp-0x2],ax
        jmp short $+15
        nop
lbl77:
        mov ax,mn4D36
        mov [bp-0x2],ax
        mov word ptr mn4D36,0xffff
lbl83:
        mov ax,[bp-0x2]
    }
}
