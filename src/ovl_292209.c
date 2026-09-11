extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0365;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_292209(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+107
        jmp LEB
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x17
        jz short $+5
        jmp LEB
L1F:
        mov ax,mn6A04
        sub ax,0x124
        jz short $+58
        push word ptr mn6A02
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
        mov ax,0x23
L4D:
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
L59:
        mov ax,0x1
        jmp LED
L5F:
        xor ax,ax
        push ax
        push word ptr mn6A02
        mov ax,0x34
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp short $+124
        nop
        nop
L75:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+106
        ja short $+110
        cmp al,0x34
        jz short $+36
        ja short $+12
        sub al,0x13
        jz short $+18
        sub al,0x19
        jz short $+20
        jmp short $+94
L8F:
        sub al,0x38
        jz short $+60
        sub al,0xc
        jz short $+56
        jmp short $+84
L99:
        mov ax,0x1e
        jmp short $-79
        nop
L9F:
        mov ax,0x20
        jmp short $-85
        nop
LA5:
        mov ax,0x22
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov cx,0x8
        push cx
        call far ptr helper_3
        mov sp,bp
        mov byte ptr mb0365,0x1
        jmp short $-114
LCD:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1f
        jmp L4D
        nop
LE5:
        mov ax,0x21
        jmp L4D
LEB:
        xor ax,ax
LED:
    }
}
