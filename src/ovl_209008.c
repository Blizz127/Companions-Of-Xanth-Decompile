extern int __near mn31FE;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_209008(int a)
{
    _asm {
        sub sp,0x6
        cmp word ptr [bp+0xe],0x0
        jz short $+40
        push word ptr mn31FE
        call far ptr helper_0
        add sp,0x2
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0xa
        jmp short $+87
L2F:
        mov ax,[bp+0x8]
        mov [bp-0x4],ax
        cmp ax,[bp+0xc]
        jg short $+76
L3A:
        mov ax,[bp+0x6]
        mov [bp-0x2],ax
        cmp ax,[bp+0xa]
        jg short $+54
L45:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_2
        sub ax,0x4
        mov [bp-0x6],ax
        cmp ax,0x11
        jnl short $+7
        mov word ptr [bp-0x6],0x11
L60:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        push word ptr [bp-0x6]
        call far ptr helper_3
        mov ax,[bp+0xa]
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jng short $-50
L79:
        mov ax,[bp+0xc]
        inc word ptr [bp-0x4]
        cmp [bp-0x4],ax
        jng short $-72
L84:
    }
}
