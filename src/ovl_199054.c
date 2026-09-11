extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb3142;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_199054(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LBB
L0F:
        jmp L12F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0xf
        jz short $+5
        jmp L12F
L23:
        cmp word ptr mn6A04,0x90
        jz short $+5
        jmp L12F
L2E:
        mov ax,0x105
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+44
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        jmp L11D
        nop
L6B:
        mov ax,0xc
        mov dx,0xf023
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0x5
        push cx
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x105
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        mov byte ptr mb3142,0x0
        call far ptr helper_5
        mov ax,0x3165
        push ds
        push ax
        call far ptr helper_6
LB2:
        mov sp,bp
LB4:
        mov ax,0x1
        jmp short $+122
        nop
        nop
LBB:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+104
        ja short $+108
        sub al,0x8
        jz short $+14
        sub al,0xa
        jz short $+16
        dec al
        jz short $+24
        sub al,0x19
        jnz short $+92
LD5:
        mov ax,0x9
        jmp short $+69
        nop
LDB:
        mov ax,0x9
        push ax
        call far ptr helper_7
        jmp short $-50
        nop
LE7:
        mov ax,0x7
        mov dx,0xf023
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x105
        push ax
        mov ax,0x90
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $-83
        mov ax,0x90
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x8
L11D:
        mov dx,0xf023
        push dx
        push ax
        call far ptr helper_2
        jmp short $-117
L129:
        mov ax,0xa
        jmp short $-15
        nop
L12F:
        xor ax,ax
L131:
    }
}
