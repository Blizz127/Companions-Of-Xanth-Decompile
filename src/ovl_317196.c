extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_317196(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+37
        jmp LD1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LD1
L1A:
        mov ax,0x5a
L1D:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_0
L27:
        mov sp,bp
L29:
        mov ax,0x1
        jmp LD3
L2F:
        mov ax,mn6A06
        cmp ax,0x5a
        jz short $+90
        jna short $+5
        jmp LD1
L3C:
        cmp al,0x1d
        jz short $+57
        ja short $+13
        sub al,0x8
        jz short $+23
        sub al,0xb
        jz short $+25
        jmp LD1
L4D:
        sub al,0x2c
        jz short $+12
        sub al,0x18
        jz short $+42
        dec al
        jz short $+44
        jmp short $+120
L5B:
        mov ax,0x56
        jmp short $-65
        nop
L61:
        mov ax,0x54
L64:
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        call far ptr helper_1
        jmp short $-76
L77:
        mov ax,0x59
        jmp short $-22
        nop
L7D:
        mov ax,0x55
        jmp short $-99
        nop
L83:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-101
        nop
L8F:
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jnz short $+25
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_4
        mov sp,bp
        push dx
        push ax
        mov ax,0x57
        jmp L1D
LB9:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_4
        mov sp,bp
        push dx
        push ax
        mov ax,0x58
        jmp L1D
        nop
LD1:
        xor ax,ax
LD3:
    }
}
