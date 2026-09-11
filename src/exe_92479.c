extern int __near mn4D38;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_92479(int a)
{
    _asm {
        sub sp,0x12
        push word ptr mn4D38
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jnl short $+5
        jmp L127
L16:
        mov bx,ax
        add bx,ax
        mov [bp-0xe],bx
        cmp word ptr [bx+0x6378],0x1
        jnl short $+5
        jmp L127
L27:
        mov ax,[bx+0x6370]
        mov [bp-0x6],ax
        mov ax,[bx+0x636c]
        mov [bp-0x4],ax
        cmp word ptr [bp+0x6],-1
        jl short $+80
        cmp word ptr [bp+0x6],0x1
        jg short $+74
        mov ax,[bp+0x6]
        add [bp-0x4],ax
        jns short $+10
        mov word ptr [bp-0x4],0x0
        jmp short $+21
        nop
L51:
        mov ax,[bx+0x6378]
        dec ax
        cmp ax,[bp-0x4]
        jnl short $+10
        mov ax,[bx+0x6378]
        dec ax
        mov [bp-0x4],ax
L63:
        mov ax,[bp-0x4]
        cmp [bp-0x6],ax
        jng short $+8
        mov [bp-0x6],ax
        jmp short $+76
        nop
L71:
        sub ax,[bx+0x637c]
        inc ax
        cmp ax,[bp-0x6]
        jng short $+65
        mov [bp-0x6],ax
L7E:
        or ax,ax
        jnl short $+58
        mov word ptr [bp-0x6],0x0
        jmp short $+51
L89:
        mov ax,[bx+0x6378]
        sub ax,[bx+0x637c]
        mov cx,[bp+0x6]
        add [bp-0x6],cx
        cmp ax,[bp-0x6]
        jnl short $+15
        mov [bp-0x6],ax
        mov cx,[bx+0x6378]
        dec cx
        mov [bp-0x4],cx
        jmp short $-41
LA9:
        cmp word ptr [bp-0x6],0x0
        jnl short $+7
        mov word ptr [bp-0x6],0x0
LB4:
        mov ax,[bp-0x6]
        mov [bp-0x4],ax
LBA:
        mov bx,[bp-0xe]
        mov ax,[bp-0x6]
        mov [bx+0x6370],ax
        mov ax,[bp-0x4]
        mov [bx+0x636c],ax
        mov ax,[bx+0x6380]
        mov [bp-0xa],ax
        mov ax,[bx+0x6384]
        cmp word ptr [bx+0x6378],0x2
        jnl short $+8
        mov ax,[bp-0xa]
        jmp short $+31
        nop
LE3:
        sub ax,[bp-0xa]
        mul word ptr [bp-0x4]
        mov bx,[bp-0xe]
        add ax,[bx+0x6378]
        sub ax,0x2
        mov cx,[bx+0x6378]
        dec cx
        sub dx,dx
        div cx
        add ax,[bp-0xa]
LFF:
        mov [bp-0x8],ax
        call far ptr helper_1
        push word ptr [bp-0x8]
        push word ptr mn4D38
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        call far ptr helper_3
        add sp,0x2
        call far ptr helper_4
L127:
    }
}
