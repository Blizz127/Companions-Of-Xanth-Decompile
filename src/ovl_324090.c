extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_324090(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+47
        jmp short $+99
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+90
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1b
        mov dx,0xf04c
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp short $+56
L39:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+16
        ja short $+46
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+22
        sub al,0x19
        jnz short $+34
L4F:
        push word ptr mn6A04
        call far ptr helper_2
L58:
        mov sp,bp
        mov ax,0x1
        jmp short $+20
L5F:
        mov ax,0x1a
        mov dx,0xf04c
        push dx
        push ax
        call far ptr helper_1
        jmp short $-20
        nop
L6F:
        xor ax,ax
L71:
    }
}
