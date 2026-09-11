extern int __near mn5A5E;

int far exe_64277(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x38
        jnc short $+25
        push word ptr [bp+0x8]
        mov es, mn5A5E
        mov bx,[bp+0x6]
        add bx,bx
        add bx,bx
        call dword ptr es:[bx+0x135a]
        mov sp,bp
        jmp short $+4
L1D:
        xor ax,ax
L1F:
    }
}
