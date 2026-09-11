extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_263082(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+53
        jmp LA1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA1
L1A:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x33
L2E:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L3A:
        mov ax,0x1
        jmp short $+102
L3F:
        mov ax,mn6A06
        cmp ax,0x13
        jz short $+52
        ja short $+10
        sub ax,0x8
        jz short $+23
        jmp short $+83
        nop
L51:
        sub ax,0x2c
        jz short $+15
        sub ax,0x18
        jc short $+72
        sub ax,0x1
        jna short $+45
        jmp short $+65
        nop
L63:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x32
        jmp short $-73
L79:
        mov ax,0x31
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-79
L8B:
        xor ax,ax
        push ax
        mov ax,0x13f
        push ax
        push word ptr mn6A06
        call far ptr helper_2
        add sp,0x6
        jmp short $+5
        nop
LA1:
        xor ax,ax
LA3:
    }
}
