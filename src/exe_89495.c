void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_89495(int a)
{
    _asm {
        sub sp,0x1a
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_0
        add sp,0x4
        cmp word ptr [bp+0x6],0x0
        jnz short $+18
        mov ax,0x4336
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $+102
        nop
L27:
        lea ax,[bp-0x14]
        push ss
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_2
        add sp,0x6
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_1
        add sp,0x4
        lea ax,[bp-0x1a]
        push ss
        push ax
        lea ax,[bp-0x18]
        push ss
        push ax
        lea cx,[bp-0x16]
        push ss
        push cx
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_3
        add sp,0x10
        push word ptr [bp+0x8]
        xor ax,ax
        push ax
        mov ax,0x7
        push ax
        mov ax,[bp+0xc]
        add ax,0x13
        push ax
        mov ax,[bp+0xa]
        add ax,0x17
        push ax
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp-0x16]
        call far ptr helper_4
        mov [bp-0x18],ax
L8A:
    }
}
