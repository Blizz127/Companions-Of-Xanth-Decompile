void far helper_0(void);
int near exe_7962(int a)
{
    _asm {
        mov si,[bp+0x4]
        mov al,[si+0xa]
        test al,0x83
        jz short $+40
        test al,0x8
        jz short $+36
        push word ptr [si+0x8]
        push word ptr [si+0x6]
        call far ptr helper_0
        add sp,0x4
        and byte ptr [si+0xa],0xf7
        xor ax,ax
        mov [si+0x6],ax
        mov [si+0x8],ax
        mov [si],ax
        mov [si+0x2],ax
        mov [si+0x4],ax
lbl31:
    }
}
