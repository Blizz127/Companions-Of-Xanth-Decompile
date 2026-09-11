extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_316878(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short lbl0F
        dec ax
        dec ax
        jz short lbl3D
        jmp short lbl8D
        nop
lbl0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short lbl8D
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x4e
lbl2B:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
lbl35:
        mov sp,bp
lbl37:
        mov ax,0x1
        jmp short lbl8F
        nop
lbl3D:
        mov ax,mn6A06
        cmp ax,0x5c
        jz short lbl87
        ja short lbl8D
        cmp al,0x2c
        jz short lbl5F
        ja short lbl57
        sub al,0x8
        jz short lbl5F
        sub al,0xb
        jz short lbl6B
        jmp short lbl8D
lbl57:
        sub al,0x44
        jz short lbl81
        dec al
        jnz short lbl8D
lbl5F:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short lbl35
        nop
lbl6B:
        mov ax,0x4b
lbl6E:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        call far ptr helper_3
        jmp short lbl37
lbl81:
        mov ax,0x4c
        jmp short lbl2B
        nop
lbl87:
        mov ax,0x4d
        jmp short lbl6E
        nop
lbl8D:
        xor ax,ax
lbl8F:
    }
}
