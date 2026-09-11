extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_316226(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LAD
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LAD
L1A:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3e
L40:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp short $+96
L51:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+74
        ja short $+84
        cmp al,0x2c
        jz short $+28
        ja short $+12
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+30
        jmp short $+68
L6B:
        sub al,0x38
        jz short $+30
        sub al,0xb
        jc short $+60
        sub al,0x1
        jna short $+22
        jmp short $+54
L79:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-56
        nop
L85:
        mov ax,0x3c
        jmp short $-72
        nop
L8B:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3d
        jmp short $-95
LA1:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-96
        nop
LAD:
        xor ax,ax
LAF:
    }
}
