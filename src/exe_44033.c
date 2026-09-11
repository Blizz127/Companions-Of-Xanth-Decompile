extern int __near mn00EC;
extern int __near mn5A22;

int far exe_44033(int a)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn00EC,0x0
        jng short $+46
        mov word ptr [bp-0x4],0x32
L14:
        mov al,[bp+0x6]
        mov es, mn5A22
        mov bx,[bp-0x4]
        cmp es:[bx],al
        jz short $+20
        add word ptr [bp-0x4],0x4
        mov ax,mn00EC
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-28
        jmp short $+9
        nop
L35:
        mov ax,0x1
        jmp short $+5
        nop
L3B:
        xor ax,ax
L3D:
    }
}
