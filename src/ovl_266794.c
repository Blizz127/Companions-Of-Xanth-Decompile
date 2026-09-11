extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_266794(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+89
        jmp L9F
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L9F
L1A:
        push word ptr mn6A02
        mov ax,0x26
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x8
L52:
        mov dx,0xf039
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+64
L63:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+27
        jmp short $+47
        nop
L73:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x6
        jmp short $-53
L89:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x7
        jmp short $-75
L9F:
        xor ax,ax
LA1:
    }
}
