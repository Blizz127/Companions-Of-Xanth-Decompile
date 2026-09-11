void far helper_0(void);
void far helper_1(void);
int far ovl_223437(int a)
{
    _asm {
        sub sp,0x6
        mov ax,[bp+0x8]
        mov [bp-0x4],ax
        cmp ax,[bp+0xc]
        jg short $+76
L0E:
        mov ax,[bp+0x6]
        mov [bp-0x2],ax
        cmp ax,[bp+0xa]
        jg short $+54
L19:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_0
        sub ax,0x4
        mov [bp-0x6],ax
        cmp ax,0x11
        jnl short $+7
        mov word ptr [bp-0x6],0x11
L34:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        push word ptr [bp-0x6]
        call far ptr helper_1
        mov ax,[bp+0xa]
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jng short $-50
L4D:
        mov ax,[bp+0xc]
        inc word ptr [bp-0x4]
        cmp [bp-0x4],ax
        jng short $-72
L58:
    }
}
