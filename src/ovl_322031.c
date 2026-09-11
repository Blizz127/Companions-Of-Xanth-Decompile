extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_322031(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LA5
L0F:
        jmp L101
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+5
        jmp L101
L23:
        cmp word ptr mn6A04,0x1b7
        jz short $+8
        mov ax,0x1f
        jmp LD0
L31:
        mov ax,0x20
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0xf
        push cx
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0x1da
        push cx
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0x1db
        push cx
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1d5
        push cx
        mov dx,0x1dc
        push dx
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1d5
        push ax
        mov ax,0x1dd
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x3acf
        push ds
        push ax
        call far ptr helper_3
L9E:
        mov sp,bp
LA0:
        mov ax,0x1
        jmp short $+96
LA5:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+22
        ja short $+84
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+24
        sub al,0x19
        jz short $+8
        sub al,0x18
        jz short $+32
        jmp short $+66
LC1:
        push word ptr mn6A04
        call far ptr helper_4
        jmp short $-44
        nop
LCD:
        mov ax,0x1d
LD0:
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_0
        jmp short $-60
        nop
LDD:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_5
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp short $-95
L101:
        xor ax,ax
L103:
    }
}
