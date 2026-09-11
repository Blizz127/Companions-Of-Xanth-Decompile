extern int __near mn4F56;
void far helper_0(void);
int far exe_105269(int a)
{
    _asm {
        sub sp,0x8
        mov word ptr [bp-0x2],0x0
        cmp word ptr [bp+0xa],0x1
        jnl short $+13
        mov word ptr mn4F56,0x1
        mov word ptr [bp+0xa],0x100
L19:
        cmp word ptr [bp+0xa],0x0
        jng short $+56
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x8],ax
        mov [bp-0x6],dx
L2B:
        push word ptr [bp+0xe]
        push word ptr [bp+0xc]
        inc word ptr [bp+0xc]
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        call far ptr helper_0
        add sp,0x8
        or ax,ax
        jz short $+17
        add word ptr [bp-0x8],0x14
        mov ax,[bp+0xa]
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-40
L55:
        mov word ptr mn4F56,0x0
        mov ax,[bp-0x2]
    }
}
