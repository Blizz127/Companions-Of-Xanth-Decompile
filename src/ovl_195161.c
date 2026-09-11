extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_195161(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+121
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+112
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x49
L2B:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
L35:
        mov sp,bp
        mov ax,0x1
        jmp short $+77
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+44
        ja short $+64
        sub al,0x8
        jz short $+14
        sub al,0xa
        jz short $+16
        dec al
        jz short $+24
        sub al,0x19
        jnz short $+48
L57:
        mov ax,0x47
        jmp short $-47
        nop
L5D:
        mov ax,0x8
        push ax
        call far ptr helper_2
        jmp short $-49
        nop
L69:
        mov ax,0x46
        jmp short $-65
        nop
L6F:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x48
        jmp short $-88
L85:
        xor ax,ax
L87:
    }
}
