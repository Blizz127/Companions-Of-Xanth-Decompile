extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_272368(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp L93
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+126
        mov ax,0x38
L1A:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+108
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+92
        ja short $+96
        cmp al,0x13
        jz short $+52
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0x6
        jz short $+36
        jmp short $+80
L45:
        sub al,0x2c
        jz short $+42
        sub al,0x18
        jz short $+60
        jmp short $+70
L4F:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x35
        jmp short $-73
L65:
        mov ax,0x37
        jmp short $-78
        nop
L6B:
        mov ax,0x32
        jmp short $-84
        nop
L71:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x34
        jmp short $-107
L87:
        mov ax,0x33
        jmp short $-112
        nop
L8D:
        mov ax,0x36
        jmp short $-118
        nop
L93:
        xor ax,ax
L95:
    }
}
