extern int __near mn642C;
extern int __near mn642E;
extern int __near mn6430;
extern int __near mn6432;

int far exe_99569(int a)
{
    _asm {
        sub sp,0x8
        cmp word ptr mn642C,-1
        jz short $+93
        mov ax,mn642C
        sub ax,0x10
        mov [bp-0x2],ax
        mov ax,mn642E
        sub ax,0x10
        mov [bp-0x4],ax
        mov ax,mn6430
        mov [bp-0x6],ax
        mov cx,mn6432
        mov [bp-0x8],cx
        cmp ax,0x12f
        jl short $+7
        mov word ptr [bp-0x6],0x13f
L33:
        cmp word ptr [bp-0x8],0xb7
        jl short $+7
        mov word ptr [bp-0x8],0xc7
L3F:
        mov ax,[bp+0x6]
        cmp [bp-0x2],ax
        jg short $+32
        mov ax,[bp+0x8]
        cmp [bp-0x4],ax
        jg short $+24
        mov ax,[bp+0x6]
        cmp [bp-0x6],ax
        jl short $+16
        mov ax,[bp+0x8]
        cmp [bp-0x8],ax
        jl short $+8
        mov ax,0x1
        jmp short $+5
        nop
L65:
        xor ax,ax
L67:
    }
}
