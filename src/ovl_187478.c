extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_187478(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+91
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+77
        ja short $+81
        sub al,0x7
        jz short $+17
        dec al
        jz short $+29
        sub al,0xb
        jz short $+47
        sub al,0x19
        jz short $+21
        jmp short $+63
        nop
L25:
        mov ax,0x9
        push ax
        call far ptr helper_0
L2E:
        mov sp,bp
        mov ax,0x1
        jmp short $+48
L35:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        jmp short $+5
L4B:
        mov ax,0x17
L4E:
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_2
        jmp short $-42
        nop
L5B:
        mov ax,0x19
        jmp short $-16
        nop
L61:
        xor ax,ax
L63:
    }
}
