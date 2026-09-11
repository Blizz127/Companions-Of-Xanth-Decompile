extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_193597(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+39
        jmp LB3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB3
L1A:
        mov ax,0xfc
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp LB5
        nop
L31:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+118
        ja short $+122
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+50
        sub al,0x19
        jz short $+8
        sub al,0x18
        jz short $+94
        jmp short $+104
L4D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x25
L61:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short $+69
        nop
L73:
        mov ax,0xfc
        push ax
        mov ax,0xd9
        push ax
        call far ptr helper_3
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x30a7
        jmp short $+5
L8B:
        mov ax,0x30b6
L8E:
        push ds
        push ax
        mov ax,0xfc
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x23
        jmp short $-68
LA7:
        mov ax,0x24
        jmp short $-73
        nop
LAD:
        mov ax,0x26
        jmp short $-79
        nop
LB3:
        xor ax,ax
LB5:
    }
}
