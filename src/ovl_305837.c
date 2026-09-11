extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_305837(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA3
L1A:
        push word ptr mn6A02
        mov ax,0x23
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
        mov ax,0xe
L40:
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp short $+86
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+70
        ja short $+74
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+26
        jmp short $+58
L6B:
        sub al,0x38
        jz short $+26
        sub al,0xc
        jz short $+22
        jmp short $+48
L75:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-52
        nop
L81:
        mov ax,0xb
        jmp short $-68
        nop
L87:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xc
        jmp short $-91
L9D:
        mov ax,0xd
        jmp short $-96
        nop
LA3:
        xor ax,ax
LA5:
    }
}
