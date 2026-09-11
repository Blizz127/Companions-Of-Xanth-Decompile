int arr[1];
void far helper(void);
int far exe_91765(int a)
{
    _asm {
        sub sp,0x2
        push word ptr [bp+0x6]
        call far ptr helper
        add sp,0x2
        or ax,ax
        jnl short $+7
        xor ax,ax
        jmp short $+11
        nop
L17:
        mov bx,ax
        add bx,ax
        mov ax,[bx+0x6378]
L1F:
    }
}
