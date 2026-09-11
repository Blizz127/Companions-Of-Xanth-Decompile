extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_275629(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+11
        dec ax
        dec ax
        jz short $+125
        jmp LCD
        nop
        nop
L11:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LCD
L1C:
        cmp word ptr mn6A04,0x165
        jnz short $+19
        mov ax,0x14
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp short $+78
L35:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x15
        jmp short $+24
        nop
L5F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x16
L74:
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
L81:
        mov ax,0x1
        jmp short $+75
        nop
L87:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+58
        ja short $+62
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+30
        sub al,0x19
        jnz short $+50
L9D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
        jmp short $-62
        nop
LB5:
        mov ax,0x11
LB8:
        mov dx,0xf03c
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $-68
LC7:
        mov ax,0x13
        jmp short $-18
        nop
LCD:
        xor ax,ax
LCF:
    }
}
