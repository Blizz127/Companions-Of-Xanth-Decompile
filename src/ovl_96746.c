extern int __near mn6A06;
extern int __near mn0290;
void far helper_0(void);
void far helper_1(void);
int far ovl_96746(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+63
        mov ax,mn6A06
        sub ax,0x12
        jz short $+7
        dec ax
        jz short $+46
        jmp short $+50
L15:
        mov ax,0x23bc
        push ds
        push ax
        push word ptr mn0290
        mov ax,0x51
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x21
L2E:
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+10
L3F:
        mov ax,0x20
        jmp short $-20
        nop
L45:
        xor ax,ax
L47:
    }
}
