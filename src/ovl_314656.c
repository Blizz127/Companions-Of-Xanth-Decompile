extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_314656(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp L9F
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L9F
L1A:
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
        mov ax,0x1a
L40:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp short $+82
L51:
        mov ax,mn6A06
        cmp ax,0x53
        jz short $+66
        ja short $+70
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+26
        jmp short $+54
L6B:
        sub al,0x44
        jz short $+26
        dec al
        jz short $+28
        jmp short $+44
L75:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-52
        nop
L81:
        mov ax,0x17
        jmp short $-68
        nop
L87:
        mov ax,0x18
        jmp short $-74
        nop
L8D:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-76
        nop
L99:
        mov ax,0x19
        jmp short $-92
        nop
L9F:
        xor ax,ax
LA1:
    }
}
