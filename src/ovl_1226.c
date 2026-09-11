void far helper_0(void);
void far helper_1(void);
int far ovl_1226(int a)
{
    _asm {
        sub sp,0x4
        call far ptr helper_0
        mov cx,ax
        mov ax,[bp+0x6]
        mov bx,dx
        cwd
        add cx,ax
        adc bx,dx
        mov [bp-0x4],cx
        mov [bp-0x2],bx
L1A:
        call far ptr helper_1
        or ax,ax
        jnz short $+19
        call far ptr helper_0
        cmp dx,[bp-0x2]
        jl short $-17
        jg short $+7
        cmp ax,[bp-0x4]
        jc short $-24
L34:
    }
}
