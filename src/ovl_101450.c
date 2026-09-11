extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
int far ovl_101450(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+89
        jmp LB5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB5
L1A:
        push word ptr mn6A04
        mov ax,0x4
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x30
L52:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L5E:
        mov ax,0x1
        jmp short $+86
L63:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+58
        ja short $+74
        sub al,0x13
        jz short $+8
        sub al,0x31
        jz short $+26
        jmp short $+64
L77:
        mov ax,0x6e
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2e
        jmp short $-57
L8D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2b
        jmp short $-79
LA3:
        mov ax,0x2f
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-85
LB5:
        xor ax,ax
LB7:
    }
}
