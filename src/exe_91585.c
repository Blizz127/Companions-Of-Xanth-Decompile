extern int __near mn4D38;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_91585(int a)
{
    _asm {
        sub sp,0xa
        push word ptr mn4D38
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x2],ax
        or ax,ax
        jl short $+113
        mov bx,ax
        add bx,ax
        mov [bp-0xa],bx
        cmp word ptr [bx+0x6378],0x0
        jz short $+99
        lea ax,[bp-0x8]
        push ss
        push ax
        lea cx,[bp-0x4]
        push ss
        push cx
        push word ptr mn4D38
        call far ptr helper_1
        add sp,0xa
        mov ax,[bp+0x6]
        sub ax,[bp-0x8]
        sub ax,0x4
        cwd
        and dx,0x7
        add ax,dx
        mov cx,0x3
        sar ax,cl
        mov [bp-0x6],ax
        mov bx,[bp-0xa]
        add ax,[bx+0x6370]
        mov [bx+0x636c],ax
        xor ax,ax
        push ax
        call far ptr helper_2
        add sp,0x2
        cmp word ptr [bp-0x6],0x0
        jl short $+26
        mov ax,[bp-0x6]
        mov bx,[bp-0xa]
        cmp [bx+0x637c],ax
        jng short $+14
        cmp [bx+0x6378],ax
        jng short $+8
        mov ax,0x1
        jmp short $+5
        nop
L85:
        xor ax,ax
L87:
    }
}
