extern int __near mn6A06;
extern char __near mb0328;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_162486(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+117
        jmp LB7
L0F:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp LB7
L1A:
        mov ax,0x5a09
        push ax
        mov ax,0x22b
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x3f
L2C:
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x3
        push dx
        call far ptr helper_2
        mov sp,bp
        mov byte ptr mb0328,0x1
        xor ax,ax
        push ax
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_3
        mov sp,bp
        call far ptr helper_4
        mov al,0x1
        push ax
        mov ax,0x1b
        push ax
        mov ax,0xa9b
        push ax
        call far ptr helper_5
        mov sp,bp
        call far ptr helper_6
L7A:
        mov ax,0x1
        jmp short $+60
L7F:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+23
        jmp short $+43
        nop
L8F:
        mov ax,0x3d
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp short $-36
        nop
LA1:
        mov ax,0x5a09
        push ax
        mov ax,0x223
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x3e
        jmp L2C
        nop
LB7:
        xor ax,ax
LB9:
    }
}
