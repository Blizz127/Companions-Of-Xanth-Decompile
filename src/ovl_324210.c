extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_324210(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+84
        jmp LCB
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LCB
L1E:
        mov ax,mn6A04
        sub ax,0x1c2
        jz short $+39
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
L3B:
        mov dx,0xf04c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $+19
        nop
L4B:
        mov ax,0x21
L4E:
        mov dx,0xf04c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
L5B:
        mov ax,0x1
        jmp short $+111
        nop
L61:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+94
        ja short $+98
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+48
        jmp short $+82
L7B:
        sub al,0x38
        jz short $+66
        sub al,0xc
        jz short $+62
        jmp short $+72
L85:
        cmp word ptr mn6A06,0x2c
        jnz short $+11
        mov ax,0x1f
        mov dx,0xf04c
        jmp short $+8
        nop
L95:
        mov ax,0x3b62
        mov dx,ds
L9A:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x1e
        jmp short $-106
LA7:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
        jmp L3B
LBF:
        mov ax,0x1d
        jmp short $-116
        nop
LC5:
        mov ax,0x20
        jmp short $-122
        nop
LCB:
        xor ax,ax
LCD:
    }
}
