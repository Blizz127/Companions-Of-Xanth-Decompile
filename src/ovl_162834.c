extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb1D00;
extern char __near mb035A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
int far ovl_162834(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp lblF1
lbl0F:
        jmp lbl155
        nop
lbl13:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp lbl155
lbl1E:
        cmp word ptr mn6A04,0x177
        jz short $+5
        jmp lblDD
lbl29:
        mov byte ptr mb1D00,0x0
        mov ax,0x5a16
        push ax
        mov ax,0x3cc
        push ax
        call far ptr helper_0
        mov sp,bp
        call far ptr helper_1
        mov ax,0xf23
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x13
        push ax
        mov ax,0xf24
        push ax
        mov ax,0xffff
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x7d0
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x20
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_5
        mov sp,bp
        mov ax,0x5a17
        push ax
        mov ax,0x3ce
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x42
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_6
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov dx,0x14
        push dx
        call far ptr helper_7
        mov sp,bp
        xor ax,ax
        push ax
        mov cx,0x12
        push cx
        mov dx,0x177
        push dx
        call far ptr helper_8
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov cx,0x12
        push cx
        call far ptr helper_8
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x15f
        push ax
        call far ptr helper_8
        jmp short $+15
lblDD:
        mov ax,0x5a16
        push ax
        mov ax,0x3d1
lblE4:
        push ax
        call far ptr helper_0
lblEA:
        mov sp,bp
        mov ax,0x1
        jmp short $+104
lblF1:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+37
        jmp short $+87
        nop
lbl101:
        push word ptr mn6A04
        mov ax,0x11
        push ax
        call far ptr helper_9
        mov sp,bp
        push dx
        push ax
        mov ax,0x41
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_6
        jmp short $-53
lbl121:
        cmp byte ptr mb035A,0x0
        jnz short $+37
        mov byte ptr mb035A,0x1
        mov ax,0x5a16
        push ax
        mov ax,0x3b9
        push ax
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_7
        jmp short $-95
lbl14B:
        mov ax,0x5a16
        push ax
        mov ax,0x3cb
        jmp short $-110
        nop
lbl155:
        xor ax,ax
lbl157:
    }
}
