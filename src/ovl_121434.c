extern int __near mn6A06;
extern int __near mn02A6;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_121434(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+37
        jmp LC3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC3
L1A:
        mov ax,0x19
L1D:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
L27:
        mov sp,bp
        mov ax,0x1
        jmp LC5
L2F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+118
        jna short $+5
        jmp LC3
L3C:
        cmp al,0x29
        jz short $+33
        ja short $+17
        sub al,0x7
        jz short $+27
        dec al
        jz short $+35
        sub al,0xb
        jz short $+37
        jmp short $+117
        nop
L51:
        sub al,0x2c
        jz short $+52
        sub al,0xc
        jz short $+54
        sub al,0xc
        jz short $+74
        jmp short $+102
L5F:
        mov ax,0x2
        push ax
        call far ptr helper_1
        jmp short $-65
        nop
L6B:
        mov ax,0x15
        jmp short $-81
        nop
L71:
        cmp word ptr mn02A6,0x2
        jl short $+7
        mov ax,0x269d
        jmp short $+5
L7D:
        mov ax,0x2694
L80:
        push ds
        push ax
        mov ax,0x13
        jmp short $-104
L87:
        mov ax,0x16
        jmp short $-109
        nop
L8D:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        jmp L1D
        nop
LA5:
        mov ax,0x14
        jmp L1D
LAB:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
        jmp L1D
LC3:
        xor ax,ax
LC5:
    }
}
