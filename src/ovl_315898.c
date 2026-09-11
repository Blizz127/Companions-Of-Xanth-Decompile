extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_315898(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA1
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
        mov ax,0x37
L40:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
L4C:
        mov ax,0x1
        jmp short $+84
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+62
        ja short $+72
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+18
        sub al,0x19
        jz short $+36
        sub al,0x18
        jz short $+38
        jmp short $+54
L6D:
        mov ax,0x36
        jmp short $-48
        nop
L73:
        mov ax,0x33
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        call far ptr helper_2
        jmp short $-59
L89:
        mov ax,0x35
        jmp short $-76
        nop
L8F:
        mov ax,0x34
        jmp short $-82
        nop
L95:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-84
        nop
LA1:
        xor ax,ax
LA3:
    }
}
