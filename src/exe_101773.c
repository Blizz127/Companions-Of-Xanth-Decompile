extern int __near mn4FAE;

int far exe_101773(int a)
{
    _asm {
        sub sp,0xa
        mov ax,mn4FAE
        mov [bp-0x6],ax
        mov word ptr [bp-0x4],0x0
        mov word ptr [bp-0x2],0x1
        or ax,ax
        jng short $+59
        mov word ptr [bp-0x8],0x4fb0
L1C:
        cmp word ptr [bp-0x8],0x4fb2
        jnc short $+47
        mov bx,[bp-0x8]
        mov ax,[bx]
        mov [bp-0xa],ax
        or ax,ax
        jz short $+10
        mov ax,[bp-0x6]
        cmp [bp-0xa],ax
        jng short $+14
L37:
        mov ax,[bp-0xa]
        mov [bp-0x6],ax
        mov ax,[bp-0x2]
        mov [bp-0x4],ax
L43:
        add word ptr [bp-0x8],0x2
        inc word ptr [bp-0x2]
        cmp word ptr [bp-0x6],0x0
        jg short $-50
L50:
        mov ax,[bp-0x4]
    }
}
