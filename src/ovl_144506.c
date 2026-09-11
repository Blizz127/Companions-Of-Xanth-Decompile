extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_144506(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L16F
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L157
L16:
        jna short $+5
        jmp L16F
L1B:
        cmp al,0x2c
        jz short $+30
        ja short $+14
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+42
        jmp L16F
        nop
L2D:
        sub al,0x38
        jz short $+40
        sub al,0xc
        jnz short $+5
        jmp LCD
L38:
        jmp L16F
L3B:
        mov ax,0x16
L3E:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_0
L48:
        mov sp,bp
        mov ax,0x1
        jmp L171
        nop
L51:
        mov ax,0x11
        jmp short $-22
        nop
L57:
        mov ax,mn6A02
        sub ax,0xa9
        jz short $+56
        sub ax,0x7
        jz short $+101
        mov ax,0xb
        push ax
        push word ptr mn6A02
        call far ptr helper_1
        mov sp,bp
        cmp ax,0x1
        sbb ax,ax
        and al,0xfa
        add ax,0x6f
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1a
        jmp short $-85
L95:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x18
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0xa9
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-125
LC7:
        mov ax,0x19
        jmp L3E
LCD:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x12
        jmp L3E
        nop
LE7:
        mov ax,0xa9
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x13
        jmp short $+59
LFF:
        mov ax,0x145
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        or ax,ax
        jz short $+65
        mov ax,0x144
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
L138:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        push word ptr mn6A04
        call far ptr helper_5
        jmp L48
        nop
L151:
        mov ax,0x15
        jmp L3E
L157:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x17
        jmp L3E
        nop
L16F:
        xor ax,ax
L171:
    }
}
