extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_319639(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+99
        jmp L12F
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+61
        jmp L12F
L1F:
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x1b
L45:
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L51:
        mov ax,0x1
        jmp L131
L57:
        mov ax,0x1d4
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_2
        mov sp,bp
        jmp L131
L6D:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L117
L78:
        jna short $+5
        jmp L12F
L7D:
        sub al,0x8
        jz short $+14
        sub al,0xb
        jz short $+40
        sub al,0x19
        jz short $+112
        jmp L12F
        nop
L8D:
        mov ax,0x1ce
        push ax
        mov ax,0x1d4
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x18
        jmp short $-94
LA5:
        mov ax,0x19
        jmp short $-99
        nop
LAB:
        mov ax,0x1ce
        push ax
        mov ax,0x1d4
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+7
        xor ax,ax
        cwd
        jmp short $+8
LC3:
        mov ax,0x14
        mov dx,0xf04a
LC9:
        push dx
        push ax
        mov ax,0x13
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1b1
        push ax
        mov ax,0x1b7
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L51
LF0:
        mov ax,0x15
        jmp L45
        nop
LF7:
        mov ax,0x1ce
        push ax
        mov ax,0x1d4
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x16
        jmp L45
        nop
L111:
        mov ax,0x17
        jmp L45
L117:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1a
        jmp L45
        nop
L12F:
        xor ax,ax
L131:
    }
}
