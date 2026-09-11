extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_263574(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L2BD
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L293
L16:
        jna short $+5
        jmp L2BD
L1B:
        cmp al,0x2c
        jz short $+40
        ja short $+14
        sub al,0x8
        jz short $+34
        sub al,0xb
        jz short $+68
        jmp L2BD
        nop
L2D:
        sub al,0x38
        jnz short $+5
        jmp LF1
L34:
        sub al,0x2
        jnz short $+5
        jmp L165
L3B:
        sub al,0xa
        jnz short $+5
        jmp L195
L42:
        jmp L2BD
L45:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x43
L59:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L65:
        mov ax,0x1
        jmp L2BF
L6B:
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        cbw
        push ax
        mov ax,0x3f
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x145
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+33
        mov ax,0xe
        push ax
        mov ax,0x146
        push ax
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jnz short $+8
        mov ax,0x40
        jmp short $+31
        nop
LB3:
        mov ax,0x41
        jmp short $+25
        nop
LB9:
        mov ax,0x143
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+11
        mov ax,0x42
LCF:
        mov dx,0xf028
        push dx
        jmp short $+6
LD5:
        mov ax,0x3539
        push ds
LD9:
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x2e
        push ax
        call far ptr helper_5
        add sp,0x2
        jmp L65
LF1:
        cmp word ptr mn6A02,0x145
        jnz short $+5
        jmp L2BD
LFC:
        cmp word ptr mn6A02,0x144
        jnz short $+5
        jmp L2BD
L107:
        cmp word ptr mn6A02,0x143
        jnz short $+5
        jmp L2BD
L112:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        push ax
        push word ptr mn6A02
        call far ptr helper_4
        add sp,0x4
        cmp ax,0x1
        sbb ax,ax
        and al,0xfa
        add ax,0x6f
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x48
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        add sp,0xe
        jmp L65
        nop
L165:
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x2
        cbw
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3546
        push ds
L189:
        push ax
        call far ptr helper_1
        add sp,0xa
        jmp L65
L195:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x45
        jmp L59
L1C1:
        mov ax,0x1
        push ax
        mov ax,0x149
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L27F
L1D8:
        mov ax,0x1
        push ax
        mov ax,0x14a
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L27F
L1EF:
        mov ax,0x1
        push ax
        mov ax,0x14b
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+126
        mov ax,0x1
        push ax
        mov ax,0x14c
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+106
        mov ax,0x1
        push ax
        mov ax,0x14d
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+86
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x2
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x47
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x6
        jmp L65
        nop
L27F:
        mov ax,0x46
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L65
        nop
L293:
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x2
        cbw
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x44
        mov dx,0xf028
        push dx
        jmp L189
L2BD:
        xor ax,ax
L2BF:
    }
}
