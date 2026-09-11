extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_200370(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp LBB
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LBB
L1A:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
L40:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp short $+110
        nop
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+70
        ja short $+96
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+26
        jmp short $+80
L6D:
        sub al,0x38
        jz short $+26
        sub al,0xc
        jz short $+22
        jmp short $+70
L77:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-54
        nop
L83:
        mov ax,0xe
        jmp short $-70
        nop
L89:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xf
        jmp short $-93
L9F:
        mov ax,0x3177
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x10
        jmp short $-120
        nop
LBB:
        xor ax,ax
LBD:
    }
}
