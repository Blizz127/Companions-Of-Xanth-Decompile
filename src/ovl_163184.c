extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0363;
extern int __near mn02D8;
extern int __near mn6A22;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_163184(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp LC3
L0F:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp LC3
L1A:
        mov ax,mn6A04
        sub ax,0x177
        jz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x45
        jmp short $+6
        nop
L39:
        mov ax,0x44
L3C:
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_1
L46:
        mov sp,bp
L48:
        mov ax,0x1
        jmp short $+122
        nop
        nop
L4F:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+27
        jmp short $+103
        nop
L5F:
        cmp byte ptr mb0363,0x0
        jz short $+7
        mov ax,0x2ba7
        jmp short $+5
L6B:
        mov ax,0x2bb0
L6E:
        push ds
        push ax
        mov ax,0x43
        jmp short $-55
L75:
        cmp word ptr mn02D8,0xa
        jnl short $+39
        mov ax,0x5a18
        push ax
        mov ax,0x3e9
        push ax
        call far ptr helper_2
        mov sp,bp
        cmp word ptr mn02D8,0xa
        jnz short $-72
        xor ax,ax
        push ax
        push ax
        mov ax,0x7
        push ax
        call far ptr helper_3
        jmp short $-89
LA1:
        cmp word ptr mn6A22,0x169
        jnz short $+12
        mov ax,0x5a18
        push ax
        mov ax,0x3ee
        jmp short $+10
        nop
LB3:
        mov ax,0x5a18
        push ax
        mov ax,0x3f3
LBA:
        push ax
        call far ptr helper_2
        jmp short $-122
        nop
LC3:
        xor ax,ax
LC5:
    }
}
