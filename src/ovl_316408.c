extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_316408(int a)
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
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x41
L2B:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
L35:
        mov sp,bp
        mov ax,0x1
        jmp short $+69
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+46
        ja short $+56
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+24
        sub al,0x19
        jz short $+8
        sub al,0x18
        jz short $+22
        jmp short $+38
L59:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-45
        nop
L65:
        mov ax,0x3f
        jmp short $-61
        nop
L6B:
        mov ax,0x40
        jmp short $-67
        nop
L71:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-69
        nop
L7D:
        xor ax,ax
L7F:
    }
}
