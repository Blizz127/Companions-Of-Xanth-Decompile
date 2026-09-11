extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_207687(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp L9B
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L9B
L1A:
        push word ptr mn6A02
        mov ax,0x2
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
        mov ax,0x4c
L40:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp short $+78
        nop
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+60
        ja short $+64
        sub al,0x8
        jz short $+14
        sub al,0xa
        jz short $+32
        dec al
        jz short $+40
        sub al,0x19
        jnz short $+48
L6D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x4a
        jmp short $-65
L83:
        mov ax,0x7
        push ax
        call far ptr helper_2
        jmp short $-66
        nop
L8F:
        mov ax,0x49
        jmp short $-82
        nop
L95:
        mov ax,0x4b
        jmp short $-88
        nop
L9B:
        xor ax,ax
L9D:
    }
}
