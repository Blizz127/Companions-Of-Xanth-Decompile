extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_198904(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short lbl0F
        dec ax
        dec ax
        jz short lbl4F
        jmp short lbl8D
        nop
lbl0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short lbl8D
        push word ptr mn6A02
        mov ax,0x3
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
lbl3D:
        mov dx,0xf023
        push dx
        push ax
        call far ptr helper_1
lbl47:
        mov sp,bp
        mov ax,0x1
        jmp short lbl8F
        nop
lbl4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short lbl77
        ja short lbl8D
        sub al,0x8
        jz short lbl65
        sub al,0xb
        jz short lbl71
        sub al,0x19
        jnz short lbl8D
lbl65:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short lbl47
        nop
lbl71:
        mov ax,0x4
        jmp short lbl3D
        nop
lbl77:
        push word ptr mn6A04
        mov ax,0x21
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x5
        jmp short lbl3D
lbl8D:
        xor ax,ax
lbl8F:
    }
}
