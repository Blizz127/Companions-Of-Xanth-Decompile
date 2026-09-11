extern int __near mn5D84;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_4455(int a)
{
    _asm {
        sub sp,0x4
        call far ptr helper_0
        mov ax,0x20
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
        mov word ptr mn5D84,0x8c
        call far ptr helper_3
        call far ptr helper_4
        add ax,0xbb8
        adc dx,0x0
        mov [bp-0x4],ax
        mov [bp-0x2],dx
L39:
        call far ptr helper_4
        cmp dx,[bp-0x2]
        jg short $+18
        jl short $+7
        cmp ax,[bp-0x4]
        jnc short $+11
L4A:
        call far ptr helper_5
        or ax,ax
        jnz short $-24
L53:
        mov ax,0x521
        mov dx,0x30cb
        push dx
        push ax
        mov ax,0x52d
        push ax
        call far ptr helper_6
        add sp,0x6
L67:
        call far ptr helper_5
        or ax,ax
        jnz short $-7
        call far ptr helper_7
    }
}
