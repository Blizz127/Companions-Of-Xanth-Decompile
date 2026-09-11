extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_314482(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA5
L1A:
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x16
        mov dx,0xf049
L43:
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp short $+88
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+66
        ja short $+76
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+18
        sub al,0x19
        jnz short $+64
L67:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-38
        nop
L73:
        mov ax,0xe
        push ax
        mov ax,0x1be
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x14
        jmp short $+5
L8B:
        mov ax,0x15
L8E:
        mov dx,0xf049
        push dx
        push ax
        mov ax,0x13
        jmp short $-83
        nop
L99:
        push word ptr mn6A04
        call far ptr helper_4
        jmp short $-88
        nop
LA5:
        xor ax,ax
LA7:
    }
}
