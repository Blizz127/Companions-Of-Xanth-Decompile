extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_144190(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+103
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+94
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xb
L2B:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+59
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+42
        ja short $+46
        sub al,0x13
        jz short $+8
        sub al,0x31
        jz short $+10
        jmp short $+36
L51:
        mov ax,0x8
        jmp short $-41
        nop
L57:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x9
        jmp short $-64
L6D:
        mov ax,0xa
        jmp short $-69
        nop
L73:
        xor ax,ax
L75:
    }
}
