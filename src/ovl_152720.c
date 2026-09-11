extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_152720(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LA1
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+126
        jna short $+5
        jmp LA1
L18:
        sub al,0x8
        jz short $+17
        sub al,0xb
        jz short $+69
        sub al,0x19
        jz short $+9
        sub al,0x18
        jz short $+83
        jmp short $+121
        nop
L2B:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        cmp word ptr mn6A06,0x2c
        jnz short $+8
        mov ax,0x2a66
        jmp short $+6
        nop
L49:
        mov ax,0x2a6b
L4C:
        push ds
        push ax
        mov ax,0x1
L51:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5D:
        mov ax,0x1
        jmp short $+67
        nop
L63:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        xor ax,ax
        jmp short $-37
        nop
L79:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2
        jmp short $-60
L8F:
        mov ax,0x3
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-66
LA1:
        xor ax,ax
LA3:
    }
}
