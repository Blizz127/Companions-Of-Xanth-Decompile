extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_298321(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+113
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+104
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xd
L2B:
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+69
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+16
        ja short $+56
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+26
        sub al,0x19
        jnz short $+44
L53:
        xor ax,ax
        push ax
        mov ax,0x195
        push ax
        push word ptr mn6A06
        call far ptr helper_2
        mov sp,bp
        jmp short $+26
L67:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xc
        jmp short $-80
L7D:
        xor ax,ax
L7F:
    }
}
