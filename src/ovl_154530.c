extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
int far ovl_154530(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+77
        jmp LFF
L0F:
        mov ax,mn6A06
        sub ax,0x33
        jz short $+10
        sub ax,0x5
        jz short $+5
        jmp LFF
L1F:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3d
L45:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp L101
L57:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LE7
L62:
        jna short $+5
        jmp LFF
L67:
        sub al,0x13
        jz short $+10
        sub al,0x2f
        jz short $+70
        jmp LFF
        nop
L73:
        mov ax,mn0256
        sub ax,0x80
        jz short $+40
        sub ax,0xc
        jz short $+41
        sub ax,0x8
        jz short $+30
        sub ax,0x73
        jz short $+37
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x37
        jmp short $-89
        nop
LA1:
        mov ax,0x34
        jmp short $-95
        nop
LA7:
        mov ax,0x35
        jmp short $-101
        nop
LAD:
        mov ax,0x36
        jmp short $-107
        nop
LB3:
        mov ax,mn0256
        sub ax,0x80
        jz short $+28
        sub ax,0xc
        jz short $+29
        sub ax,0x8
        jz short $+24
        sub ax,0x73
        jz short $+25
        sub ax,0x5
        jz short $+20
        mov ax,0x3b
        jmp L45
LD5:
        mov ax,0x39
        jmp L45
LDB:
        mov ax,0x38
        jmp L45
LE1:
        mov ax,0x3a
        jmp L45
LE7:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3c
        jmp L45
        nop
LFF:
        xor ax,ax
L101:
    }
}
