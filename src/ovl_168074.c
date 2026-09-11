extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_168074(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short lbl0F
        dec ax
        dec ax
        jz short lbl13
        jmp lbl8F
lbl0F:
        jmp short lbl8F
        nop
        nop
lbl13:
        mov ax,mn6A06
        cmp ax,0x45
        jz short lbl89
        ja short lbl8F
        cmp al,0x13
        jz short lbl7D
        ja short lbl2D
        sub al,0x8
        jz short lbl37
        sub al,0xa
        jz short lbl6F
        jmp short lbl8F
lbl2D:
        sub al,0x2c
        jz short lbl37
        sub al,0x18
        jz short lbl83
        jmp short lbl8F
lbl37:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        cmp word ptr mn6A06,0x2c
        jnz short lbl55
        mov ax,0x2c74
        jmp short lbl58
        nop
lbl55:
        mov ax,0x2c79
lbl58:
        push ds
        push ax
        mov ax,0x15
lbl5D:
        mov dx,0xf01c
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short lbl91
        nop
lbl6F:
        mov ax,0x1
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp short lbl8F
        nop
lbl7D:
        mov ax,0x13
        jmp short lbl5D
        nop
lbl83:
        mov ax,0x14
        jmp short lbl5D
        nop
lbl89:
        mov ax,0x16
        jmp short lbl5D
        nop
lbl8F:
        xor ax,ax
lbl91:
    }
}
