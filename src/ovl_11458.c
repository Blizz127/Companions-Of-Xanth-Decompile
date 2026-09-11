extern char __near mb416E;
extern int __near mn5D96;
extern int __near mn027E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_11458(int a)
{
    _asm {
        sub sp,0x2
        call far ptr helper_0
        test byte ptr mb416E,0x6
        jz short $+16
        cmp word ptr mn5D96,0x1
        jng short $+9
        mov word ptr [bp-0x2],0x42
        jmp short $+7
L1D:
        mov word ptr [bp-0x2],0x2d
L22:
        push word ptr [bp-0x2]
        call far ptr helper_1
        add sp,0x2
        mov ax,0x3b
        push ax
        mov cx,mn5D96
        mov dx,cx
        add cx,cx
        add cx,cx
        add cx,cx
        add cx,dx
        add cx,0x6e
        push cx
        mov cx,0x37
        push cx
        mov dx,0x6e
        push dx
        mov dx,0x2
        push dx
        call far ptr helper_2
        add sp,0xa
        xor ax,ax
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x3b
        push ax
        mov ax,0xcc
        push ax
        mov ax,0x37
        push ax
        mov ax,mn5D96
        mov cx,ax
        add ax,ax
        add ax,ax
        add ax,ax
        add ax,cx
        add ax,0x6f
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0xa
        mov ax,0x7f
        imul word ptr mn5D96
        add ax,0x6
        mov cx,0xa
        cwd
        idiv cx
        mov mn027E,ax
        call far ptr helper_3
    }
}
