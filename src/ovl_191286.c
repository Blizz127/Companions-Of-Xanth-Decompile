extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_191286(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+59
        jmp LB1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0xf
        jz short $+5
        jmp LB1
L1F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x7
L33:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+113
        nop
L45:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+96
        ja short $+100
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+18
        sub al,0x19
        jz short $+54
        sub al,0xc
        jz short $+56
        jmp short $+82
L61:
        mov ax,0x4
        jmp short $-49
        nop
L67:
        push word ptr mn6A04
        mov ax,0x2
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
        mov ax,0x2
        jmp short $-90
L8F:
        mov ax,0x3
        jmp short $-95
        nop
L95:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x6
        jmp short $-118
LAB:
        mov ax,0x5
        jmp short $-123
        nop
LB1:
        xor ax,ax
LB3:
    }
}
