extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_200148(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+55
        jmp LD5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LD5
L1A:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xd
L2E:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L3A:
        mov ax,0x1
        jmp LD7
        nop
L41:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LCF
L4C:
        jna short $+5
        jmp LD5
L51:
        sub al,0x8
        jz short $+16
        sub al,0xa
        jz short $+34
        dec al
        jz short $+76
        sub al,0x19
        jz short $+88
        jmp short $+116
L63:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp short $-73
L79:
        mov ax,0xc
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1388
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x5a03
        push ax
        mov ax,0x169
        push ax
        call far ptr helper_3
LA2:
        add sp,0x4
        jmp short $-107
LA7:
        mov ax,0x8
LAA:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_1
        jmp short $-18
        nop
LB7:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x9
        jmp L2E
LCF:
        mov ax,0xb
        jmp short $-40
        nop
LD5:
        xor ax,ax
LD7:
    }
}
