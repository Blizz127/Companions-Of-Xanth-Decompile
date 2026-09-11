extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_309237(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+99
        jmp L9D
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L9D
L1A:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+34
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x19
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        jmp short $+11
L4D:
        mov ax,0x42
        push ax
        call far ptr helper_3
L56:
        mov sp,bp
        mov ax,0x1a
L5B:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short $+53
        nop
L6D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+16
        ja short $+40
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+26
        sub al,0x19
        jnz short $+28
L83:
        xor ax,ax
        push ax
        mov ax,0x1b2
        push ax
        push word ptr mn6A06
        call far ptr helper_4
        mov sp,bp
        jmp short $+10
L97:
        mov ax,0x18
        jmp short $-63
        nop
L9D:
        xor ax,ax
L9F:
    }
}
