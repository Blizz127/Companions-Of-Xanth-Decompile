extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_270704(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short lbl0F
        dec ax
        dec ax
        jz short lbl2D
        jmp short lbl8D
        nop
lbl0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short lbl8D
        mov ax,0x15a
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp short lbl8F
        nop
lbl2D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short lbl6D
        ja short lbl8D
        cmp al,0x2c
        jz short lbl51
        ja short lbl47
        sub al,0x8
        jz short lbl51
        sub al,0xb
        jz short lbl61
        jmp short lbl8D
lbl47:
        sub al,0x38
        jz short lbl67
        sub al,0xc
        jz short lbl67
        jmp short lbl8D
lbl51:
        push word ptr mn6A04
        call far ptr helper_1
lbl5A:
        mov sp,bp
        mov ax,0x1
        jmp short lbl8F
lbl61:
        mov ax,0xd
        jmp short lbl81
        nop
lbl67:
        mov ax,0xe
        jmp short lbl81
        nop
lbl6D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0xf
lbl81:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_3
        jmp short lbl5A
lbl8D:
        xor ax,ax
lbl8F:
    }
}
