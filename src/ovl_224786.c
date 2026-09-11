extern int __near mn5E0A;
extern int __near mn5B04;

int far ovl_224786(int a)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn5E0A,0x0
        jz short $+56
        mov word ptr [bp-0x4],0x2
L14:
        mov bx,[bp-0x4]
        mov es, mn5B04
        mov al,es:[bx]
        cbw
        cmp ax,[bp+0x6]
        jnz short $+12
        mov al,es:[bx+0x1]
        cbw
        cmp ax,[bp+0x8]
        jz short $+19
L2E:
        add word ptr [bp-0x4],0x4
        mov ax,mn5E0A
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jc short $-39
        jmp short $+8
L3F:
        mov ax,[bp-0x2]
        inc ax
        jmp short $+4
L45:
        xor ax,ax
L47:
    }
}
