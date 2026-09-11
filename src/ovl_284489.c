extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_284489(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+53
        jmp L9D
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L9D
L1A:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1c
L2E:
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+98
L3F:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+61
        jmp short $+81
        nop
L4F:
        mov ax,0x175
        push ax
        mov ax,0x177
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x19
        jmp short $+5
L67:
        mov ax,0x1a
L6A:
        mov dx,0xf040
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
        jmp short $-86
        nop
L87:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1b
        jmp short $-109
L9D:
        xor ax,ax
L9F:
    }
}
