extern char __near mb02FA;
extern char __near mb02FB;
extern char __near mb02FC;
extern char __near mb02FD;
void far helper_0(void);
int far ovl_32095(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+16
        dec ax
        jz short $+21
        dec ax
        jz short $+26
        dec ax
        jz short $+59
        dec ax
        jz short $+64
        jmp short $+76
L15:
        mov byte ptr mb02FA,0x1
        jmp short $+69
        nop
L1D:
        mov byte ptr mb02FB,0x1
        jmp short $+61
        nop
L25:
        mov ax,0x1
        mov mb02FC,al
        push ax
        mov cx,0x4
        push cx
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        mov ax,0x8026
        push ax
        jmp short $+20
        nop
L49:
        mov byte ptr mb02FD,0x1
        jmp short $+17
        nop
L51:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
L5A:
        call far ptr helper_0
L5F:
    }
}
