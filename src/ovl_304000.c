extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_304000(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+89
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+61
        ja short $+79
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+29
        sub al,0x19
        jz short $+9
        sub al,0x13
        jz short $+37
        jmp short $+61
        nop
L25:
        push word ptr mn6A04
        call far ptr helper_0
L2E:
        mov sp,bp
        mov ax,0x1
        jmp short $+46
L35:
        mov ax,0x2b
L38:
        mov dx,0xf047
        push dx
        push ax
        call far ptr helper_1
        jmp short $-20
        nop
L45:
        mov ax,0x2c
        jmp short $-16
        nop
L4B:
        xor ax,ax
        push ax
        mov ax,0x19d
        push ax
        push word ptr mn6A06
        call far ptr helper_2
        mov sp,bp
        jmp short $+4
L5F:
        xor ax,ax
L61:
    }
}
