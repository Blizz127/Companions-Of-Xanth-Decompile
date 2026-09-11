extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_275843(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp L8F
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+122
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1c
L2B:
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+87
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x47
        jz short $+70
        ja short $+74
        cmp al,0x38
        jz short $+36
        ja short $+12
        sub al,0x13
        jz short $+18
        sub al,0x19
        jz short $+20
        jmp short $+58
L57:
        sub al,0x44
        jz short $+20
        dec al
        jz short $+38
        jmp short $+48
L61:
        mov ax,0x17
        jmp short $-57
        nop
L67:
        mov ax,0x19
        jmp short $-63
        nop
L6D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        jmp short $-86
L83:
        mov ax,0x1a
        jmp short $-91
        nop
L89:
        mov ax,0x1b
        jmp short $-97
        nop
L8F:
        xor ax,ax
L91:
    }
}
