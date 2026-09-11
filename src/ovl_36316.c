extern char __near mb0302;
extern char __near mb0303;
void far helper_0(void);
int far ovl_36316(int a)
{
    _asm {
        mov ax,0x1
        push ax
        mov ax,0x3
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+10
        dec ax
        jz short $+25
        dec ax
        jz short $+48
        jmp short $+51
L21:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        jmp short $+33
L33:
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        mov byte ptr mb0302,0x1
        jmp short $+8
        nop
L4D:
        mov byte ptr mb0303,0x1
L52:
    }
}
