extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_69954(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+117
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+103
        ja short $+107
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+51
        sub al,0x19
        jz short $+47
        sub al,0xe
        jz short $+43
        jmp short $+89
        nop
L25:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x36
L39:
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
L43:
        mov sp,bp
        mov ax,0x1
        jmp short $+53
        nop
L4B:
        mov ax,0x35
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xfa0
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x5a10
        push ax
        mov ax,0x1a7
        push ax
        call far ptr helper_3
        jmp short $-47
        nop
L75:
        mov ax,0x37
        jmp short $-63
        nop
L7B:
        xor ax,ax
L7D:
    }
}
