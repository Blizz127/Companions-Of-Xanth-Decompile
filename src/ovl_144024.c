extern int __near mn6A06;
extern char __near mb02F3;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_144024(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L9F
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+120
        jna short $+5
        jmp L9F
L18:
        sub al,0x7
        jz short $+17
        sub al,0xc
        jz short $+63
        sub al,0x19
        jz short $+65
        sub al,0x18
        jz short $+93
        jmp short $+119
        nop
L2B:
        cmp byte ptr mb02F3,0x0
        jz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x7
        jmp short $+49
        nop
L49:
        mov ax,0x5a03
        push ax
        mov ax,0x15c
        push ax
        call far ptr helper_1
L56:
        mov sp,bp
        mov ax,0x1
        jmp short $+70
L5D:
        mov ax,0x3
        jmp short $+23
        nop
L63:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x5
L77:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_2
        jmp short $-43
L83:
        mov ax,0x4
        jmp short $-15
        nop
L89:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x6
        jmp short $-38
L9F:
        xor ax,ax
LA1:
    }
}
