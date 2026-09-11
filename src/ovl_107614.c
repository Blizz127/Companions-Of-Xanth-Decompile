extern int __near mn6A06;
extern int __near mn0256;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_107614(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L10D
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L107
L16:
        jna short $+5
        jmp L10D
L1B:
        cmp al,0x24
        jnz short $+5
        jmp LB3
L22:
        ja short $+13
        sub al,0x13
        jz short $+27
        sub al,0xb
        jz short $+45
        jmp L10D
L2F:
        sub al,0x38
        jnz short $+5
        jmp LC9
L36:
        sub al,0xc
        jnz short $+5
        jmp LEF
L3D:
        jmp L10D
        nop
L41:
        mov ax,0x30
L44:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_0
L4E:
        mov sp,bp
L50:
        mov ax,0x1
        jmp L10F
        nop
L57:
        mov ax,0x15
        push ax
        push word ptr mn0256
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x2527
        jmp short $+5
L6F:
        mov ax,0x252e
L72:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x34
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        mov ax,0x116
        push ax
        mov ax,0x75
        push ax
        call far ptr helper_4
        jmp short $-99
LB3:
        xor ax,ax
        push ax
        mov ax,0x77
        push ax
        push word ptr mn6A06
        call far ptr helper_5
        add sp,0x6
        jmp short $+73
        nop
LC9:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x33
LDE:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L50
        nop
LEF:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x31
        jmp short $-38
        nop
L107:
        mov ax,0x32
        jmp L44
L10D:
        xor ax,ax
L10F:
    }
}
