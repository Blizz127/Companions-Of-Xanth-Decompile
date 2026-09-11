extern int __near mn4D38;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_92021(int a)
{
    _asm {
        sub sp,0x16
        push word ptr mn4D38
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x2],ax
        or ax,ax
        jnl short $+5
        jmp LCA
L19:
        mov bx,ax
        add bx,ax
        mov [bp-0x16],bx
        cmp word ptr [bx+0x6378],0x2
        jnl short $+5
        jmp LCA
L2A:
        mov ax,[bx+0x6380]
        mov [bp-0xe],ax
        mov ax,[bx+0x6384]
        mov [bp-0x10],ax
        lea ax,[bp-0xa]
        push ss
        push ax
        lea cx,[bp-0x8]
        push ss
        push cx
        mov cx,0x2
        push cx
        push word ptr mn4D38
        call far ptr helper_1
        add sp,0xc
        mov ax,[bp-0xa]
        mov [bp-0x12],ax
L58:
        lea ax,[bp-0x6]
        push ss
        push ax
        lea cx,[bp-0x4]
        push ss
        push cx
        call far ptr helper_2
        add sp,0x8
        mov [bp-0xc],ax
        mov ax,[bp-0xa]
        sub ax,[bp+0x6]
        add ax,[bp-0x6]
        mov [bp-0x14],ax
        cmp ax,[bp-0xe]
        jnc short $+8
        mov ax,[bp-0xe]
        mov [bp-0x14],ax
L84:
        mov ax,[bp-0x10]
        cmp [bp-0x14],ax
        jna short $+5
        mov [bp-0x14],ax
L8F:
        mov ax,[bp-0x12]
        cmp [bp-0x14],ax
        jz short $+47
        mov ax,[bp-0x14]
        mov [bp-0x12],ax
        mov cx,ax
        mov bx,[bp-0x16]
        sub cx,[bp-0xe]
        mov ax,[bx+0x6378]
        mul cx
        mov cx,[bp-0x10]
        sub cx,[bp-0xe]
        sub dx,dx
        div cx
        mov [bx+0x636c],ax
        xor ax,ax
        push ax
        call far ptr helper_3
        add sp,0x2
LC4:
        cmp word ptr [bp-0xc],0x0
        jnz short $-112
LCA:
    }
}
