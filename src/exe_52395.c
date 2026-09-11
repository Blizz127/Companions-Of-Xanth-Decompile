extern int __near mn0102;
extern int __near mn5A32;

int far exe_52395(int a)
{
    _asm {
        sub sp,0x6
        mov ax,mn0102
        dec ax
        mov [bp-0x4],ax
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn0102,0x0
        jng short $+45
        mov word ptr [bp-0x6],0x0
L1B:
        mov ax,[bp+0x6]
        mov es, mn5A32
        mov bx,[bp-0x6]
        cmp es:[bx],ax
        jz short $+19
        add word ptr [bp-0x6],0x2
        mov ax,mn0102
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-28
        jmp short $+8
L3B:
        mov ax,[bp-0x2]
        mov [bp-0x4],ax
L41:
        mov ax,[bp-0x4]
    }
}
