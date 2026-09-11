void far helper_0(void);
void far helper_1(void);
int far exe_105755(int a)
{
    _asm {
        sub sp,0x6
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        jmp short $+36
L19:
        push word ptr [bp+0xe]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_1
        add sp,0xa
        mov ax,[bp+0xe]
        add [bp+0x6],ax
        add word ptr [bp-0x4],0x140
L3B:
        mov ax,[bp+0x10]
        dec word ptr [bp+0x10]
        or ax,ax
        jg short $-42
    }
}
