extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_321205(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+49
        jmp LB1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB1
L1A:
        cmp word ptr mn6A04,0x1c2
        jz short $+5
        jmp LB1
L25:
        push word ptr mn6A04
        push word ptr mn6A02
        mov ax,0x4d
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp short $+123
        nop
L3B:
        mov ax,mn6A06
        cmp ax,0x4d
        jz short $+60
        ja short $+110
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+32
        sub al,0x19
        jz short $+34
        sub al,0x19
        jz short $+36
        jmp short $+92
L57:
        mov ax,0x7
L5A:
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+74
L6B:
        mov ax,0x5
        jmp short $-20
        nop
L71:
        mov ax,0x6
        jmp short $-26
        nop
L77:
        mov ax,0x8
        jmp short $-32
        nop
L7D:
        cmp word ptr mn6A02,0x1c2
        jnz short $+24
        mov ax,0x1c2
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x9
        jmp short $-63
L9B:
        push word ptr mn6A02
        mov ax,0x3
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp short $-85
LB1:
        xor ax,ax
LB3:
    }
}
