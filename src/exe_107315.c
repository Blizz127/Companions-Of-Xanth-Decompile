extern int __near mn4F68;
void far helper_0(void);
int far exe_107315(int a)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn4F68,0x0
        jng short $+63
        mov word ptr [bp-0x4],0x6776
L14:
        mov bx,[bp-0x2]
        cmp byte ptr [bx+0x676a],0xff
        jnz short $+15
        mov al,[bx+0x6764]
        dec al
        mov [bx+0x6770],al
        jmp short $+8
        nop
L2B:
        mov byte ptr [bx+0x6770],0x0
L30:
        call far ptr helper_0
        mov bx,[bp-0x4]
        add [bx],ax
        adc [bx+0x2],dx
        add word ptr [bp-0x4],0x4
        mov ax,mn4F68
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-54
L4C:
    }
}
