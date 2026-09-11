extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_146718(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L9F
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L99
L16:
        jna short $+5
        jmp L9F
L1B:
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+50
        sub al,0x19
        jz short $+8
        sub al,0x18
        jz short $+90
        jmp short $+116
L2D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x23
L41:
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_1
L4B:
        mov sp,bp
        mov ax,0x1
        jmp short $+81
        nop
L53:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x21
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-53
        nop
L83:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x22
        jmp short $-86
L99:
        mov ax,0x24
        jmp short $-91
        nop
L9F:
        xor ax,ax
LA1:
    }
}
