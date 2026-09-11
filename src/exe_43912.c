extern int __near mn00EC;
extern int __near mn5A22;
extern int __near mn54I;
extern int __near mn00EE;
void far helper_0(void);
int far exe_43912(int a)
{
    _asm {
        sub sp,0x6
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn00EC,0x0
        jng short $+101
        mov word ptr [bp-0x6],0x32
lbl14:
        mov al,[bp+0x6]
        mov es, mn5A22
        mov bx,[bp-0x6]
        cmp es:[bx],al
        jz short $+20
        add word ptr [bp-0x6],0x4
        mov ax,mn00EC
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-28
        jmp short $+64
        nop
lbl35:
        mov ax,mn00EC
        sub ax,[bp-0x2]
        dec ax
        jz short $+38
        add ax,ax
        add ax,ax
        push ax
        mov ax,[bp-0x2]
        add ax,ax
        add ax,ax
        mov cx,ax
        add ax,0x36
        mov dx,0x3420
        push dx
        push ax
        add cx, offset mn54I
        push dx
        push cx
        call far ptr helper_0
        add sp,0xa
lbl62:
        mov ax,mn00EE
        cmp [bp-0x2],ax
        jg short $+6
        dec word ptr mn00EE
lbl6E:
        dec word ptr mn00EC
lbl72:
    }
}
