extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_177799(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short lbl0B
        jmp lblA9
lbl0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short lbl16
        jmp lblA3
lbl16:
        jna short lbl1B
        jmp lblA9
lbl1B:
        cmp al,0x13
        jz short lbl73
        ja short lbl2D
        sub al,0x8
        jz short lbl37
        sub al,0xa
        jz short lbl4B
        jmp short lblA9
        nop
        nop
lbl2D:
        sub al,0x2c
        jz short lbl79
        sub al,0x18
        jz short lbl9D
        jmp short lblA9
lbl37:
        mov ax,0x33
lbl3A:
        mov dx,0xf00b
        push dx
lbl3E:
        push ax
        call far ptr helper_0
lbl44:
        mov sp,bp
lbl46:
        mov ax,0x1
        jmp short lblAB
lbl4B:
        mov ax,mn6A04
        sub ax,0xd1
        jz short lbl5B
        dec ax
        jz short lbl61
        dec ax
        jz short lbl67
        jmp short lbl46
lbl5B:
        mov ax,0x1
        jmp short lbl6A
        nop
lbl61:
        mov ax,0x7
        jmp short lbl6A
        nop
lbl67:
        mov ax,0x3
lbl6A:
        push ax
        call far ptr helper_1
        jmp short lbl44
        nop
lbl73:
        mov ax,0x31
        jmp short lbl3A
        nop
lbl79:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x32
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp short lbl46
lbl9D:
        mov ax,0x2f3d
        push ds
        jmp short lbl3E
lblA3:
        mov ax,0x34
        jmp short lbl3A
        nop
lblA9:
        xor ax,ax
lblAB:
    }
}
