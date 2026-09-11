extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_321823(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+107
        jmp LC7
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+5
        jmp LC7
L1F:
        mov ax,mn6A04
        sub ax,0x1b7
        jz short $+58
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
        mov ax,0x1c
L4D:
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+109
        nop
L5F:
        mov ax,0x1db
        push ax
        push word ptr mn6A04
        mov ax,0x4f
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp short $+87
        nop
L75:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+70
        ja short $+74
        cmp al,0x2c
        jz short $+36
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+20
        jmp short $+58
L8F:
        sub al,0x36
        jz short $+26
        sub al,0xe
        jz short $+22
        jmp short $+48
L99:
        mov ax,0x19
        jmp short $-79
        nop
L9F:
        mov ax,0x17
        jmp short $-85
        nop
LA5:
        mov ax,0x18
        jmp short $-91
        nop
LAB:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1b
        jmp short $-114
LC1:
        mov ax,0x1a
        jmp short $-119
        nop
LC7:
        xor ax,ax
LC9:
    }
}
