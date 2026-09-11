extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_165135(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L8F
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+104
        ja short $+124
        sub al,0x8
        jz short $+14
        sub al,0xb
        jz short $+32
        sub al,0x7
        jz short $+78
        sub al,0x12
        jnz short $+108
L25:
        xor ax,ax
        push ax
        mov ax,0xca
        push ax
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp short $+90
        nop
        nop
L3B:
        mov ax,0xe
        push ax
        mov ax,0xca
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x2bd3
        jmp short $+5
L53:
        mov ax,0x2bd8
L56:
        push ds
        push ax
        mov ax,0x2
L5B:
        mov dx,0xf01a
        push dx
        push ax
        call far ptr helper_2
L65:
        mov sp,bp
        mov ax,0x1
        jmp short $+39
        nop
L6D:
        mov ax,0x1
        push ax
        call far ptr helper_3
        jmp short $-17
        nop
L79:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_4
        mov sp,bp
        push dx
        push ax
        mov ax,0x3
        jmp short $-50
L8F:
        xor ax,ax
L91:
    }
}
