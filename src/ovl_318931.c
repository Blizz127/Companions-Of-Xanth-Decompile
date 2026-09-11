extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_318931(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+89
        jmp short $+127
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+7
        sub ax,0x10
        jnz short $+113
L1C:
        cmp word ptr mn6A04,0x1c3
        jnz short $+9
        mov ax,0x8
        jmp short $+42
        nop
        nop
L2B:
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
        mov ax,0x9
L51:
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
L5B:
        mov sp,bp
        mov ax,0x1
        jmp short $+45
        nop
L63:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+16
        ja short $+32
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+18
        sub al,0x19
        jnz short $+20
L79:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-39
        nop
L85:
        mov ax,0x7
        jmp short $-55
        nop
L8B:
        xor ax,ax
L8D:
    }
}
