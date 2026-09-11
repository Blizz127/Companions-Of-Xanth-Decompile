extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_206819(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp LE5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LE5
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
        mov ax,0x38
L40:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L4C:
        mov ax,0x1
        jmp LE7
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LDF
L5E:
        jna short $+5
        jmp LE5
L63:
        cmp al,0x2c
        jz short $+26
        ja short $+14
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+56
        jmp short $+116
        nop
        nop
L75:
        sub al,0x38
        jz short $+84
        sub al,0xc
        jz short $+80
        jmp short $+104
L7F:
        cmp word ptr mn6A06,0x2c
        jnz short $+7
        mov ax,0x31ef
        jmp short $+5
L8B:
        mov ax,0x31f4
L8E:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x35
        jmp short $-101
LA7:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x34
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-125
LCB:
        mov ax,0x36
LCE:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L4C
        nop
LDF:
        mov ax,0x37
        jmp short $-20
        nop
LE5:
        xor ax,ax
LE7:
    }
}
