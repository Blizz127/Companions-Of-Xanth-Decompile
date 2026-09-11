extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_145602(int a)
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
        mov ax,0xb0
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
        jz short lbl87
        ja short lbl8D
        sub al,0x13
        jz short lbl45
        sub al,0x19
        jz short lbl7B
        sub al,0x18
        jz short lbl81
        jmp short lbl8D
lbl45:
        mov ax,0xb0
        push ax
        mov ax,0xb1
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short lbl61
        mov ax,0x5
        mov dx,0xf013
        jmp short lbl64
        nop
lbl61:
        xor ax,ax
        cwd
lbl64:
        push dx
        push ax
        mov ax,0x4
lbl69:
        mov dx,0xf013
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short lbl8F
        nop
lbl7B:
        mov ax,0x7
        jmp short lbl69
        nop
lbl81:
        mov ax,0x6
        jmp short lbl69
        nop
lbl87:
        mov ax,0x8
        jmp short lbl69
        nop
lbl8D:
        xor ax,ax
lbl8F:
    }
}
