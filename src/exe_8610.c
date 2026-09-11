extern void __near nc00DD(void);
extern void __near nc0055(void);
void far helper_0(void);
int far exe_8610(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jnz short $+10
        xor ax,ax
        push ax
        call nc00DD
        jmp short $+64
lbl11:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call nc0055
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0xffff
        jmp short $+43
        nop
lbl27:
        mov si,[bp+0x6]
        sub si,0x5420
        add si,0x5510
        test byte ptr [si],0x40
        jz short $+26
        les bx, [bp+0x6]
        sub ah,ah
        mov al,es:[bx+0xb]
        push ax
        call far ptr helper_0
        add sp,0x2
        cmp ax,0x1
        cmc
        sbb ax,ax
lbl4F:
    }
}
