extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn0290;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_122586(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short lbl0B
        jmp lblFF
lbl0B:
        mov ax,mn6A06
        cmp ax,0x47
        jnz short lbl16
        jmp lblB9
lbl16:
        jna short lbl1B
        jmp lblFF
lbl1B:
        cmp al,0x38
        jz short lbl83
        ja short lbl2D
        sub al,0x2
        jz short lbl39
        sub al,0x11
        jz short lbl6D
        jmp lblFF
        nop
lbl2D:
        sub al,0x44
        jz short lbl8F
        dec al
        jz short lbl95
        jmp lblFF
        nop
lbl39:
        mov ax,mn6A02
        sub ax,0x91
        jz short lbl49
        sub ax,0xa
        jz short lbl5F
        jmp lblFF
lbl49:
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0x48
lbl54:
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp lbl101
lbl5F:
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x47
        jmp short lbl54
        nop
lbl6D:
        mov ax,0x32
lbl70:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
lbl7D:
        mov ax,0x1
        jmp short lbl101
        nop
lbl83:
        cmp word ptr mn6A02,0x17
        jnz short lblFF
        mov ax,0x35
        jmp short lbl70
lbl8F:
        mov ax,0x33
        jmp short lbl70
        nop
lbl95:
        push word ptr mn0290
        mov ax,0x11
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x34
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short lbl7D
lblB9:
        mov ax,mn6A02
        sub ax,0x9b
        jz short lblC7
        mov ax,0x37
        jmp short lbl70
        nop
lblC7:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x36
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp lbl7D
        nop
lblFF:
        xor ax,ax
lbl101:
    }
}
