extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_288232(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+129
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+97
        ja short $+119
        sub al,0x7
        jz short $+19
        dec al
        jz short $+53
        sub al,0xb
        jz short $+61
        sub al,0x19
        jz short $+45
        jmp short $+101
        nop
        nop
        nop
L27:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xb
L3B:
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_1
L45:
        mov sp,bp
        mov ax,0x1
        jmp short $+63
        nop
L4D:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-17
        nop
L59:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x9
        jmp short $-50
L6F:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
        jmp short $-73
        nop
L87:
        xor ax,ax
L89:
    }
}
