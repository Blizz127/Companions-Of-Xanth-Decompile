extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_299282(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+39
        jmp LB9
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB9
L1A:
        mov ax,0x194
        push ax
        push word ptr mn6A04
L22:
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp LBB
        nop
L31:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+124
        ja short $+128
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+22
        sub al,0x19
        jz short $+8
        sub al,0x18
        jz short $+88
        jmp short $+110
L4D:
        xor ax,ax
        push ax
        mov ax,0x195
        push ax
        jmp short $-50
        nop
L57:
        mov ax,0xa
        push ax
        mov ax,0x195
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x1c
        jmp short $+6
        nop
L71:
        mov ax,0x1d
L74:
        mov dx,0xf046
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
L9B:
        mov ax,0x1
        jmp short $+29
        nop
LA1:
        mov ax,0x1e
LA4:
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        jmp short $-22
LB3:
        mov ax,0x1f
        jmp short $-18
        nop
LB9:
        xor ax,ax
LBB:
    }
}
