extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_262014(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA7
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA7
L1A:
        push word ptr mn6A02
        mov ax,0x3
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
        mov ax,0x20
L40:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+90
L51:
        mov ax,mn6A06
        cmp ax,0x13
        jz short $+50
        ja short $+10
        sub ax,0x8
        jz short $+23
        jmp short $+71
        nop
L63:
        sub ax,0x2c
        jz short $+15
        sub ax,0x18
        jc short $+60
        sub ax,0x1
        jna short $+47
        jmp short $+53
        nop
L75:
        xor ax,ax
        push ax
        mov ax,0x144
L7B:
        push ax
        push word ptr mn6A06
        call far ptr helper_2
        mov sp,bp
        jmp short $+34
L89:
        mov ax,0x144
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1f
        jmp short $-93
L9F:
        xor ax,ax
        push ax
        mov ax,0x13f
        jmp short $-42
LA7:
        xor ax,ax
LA9:
    }
}
