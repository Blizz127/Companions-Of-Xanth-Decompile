extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb31C2;
extern char __near mb034A;
extern int __near mn02CC;
extern char __near mb0351;
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
int far ovl_204941(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+40
        jmp L22F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L22F
L1E:
        mov ax,0x121
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_0
        add sp,0x6
        jmp L231
L35:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L217
L40:
        jna short $+5
        jmp L22F
L45:
        cmp al,0x2c
        jz short $+30
        ja short $+14
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+100
        jmp L22F
        nop
L57:
        sub al,0x2f
        jz short $+120
        sub al,0x15
        jnz short $+5
        jmp L1B7
L62:
        jmp L22F
L65:
        cmp word ptr mn6A06,0x2c
        jnz short $+11
        mov ax,0x10
        mov dx,0xf025
        jmp short $+6
        nop
L75:
        xor ax,ax
        cwd
L78:
        push dx
        push ax
        cmp word ptr mn6A06,0x2c
        jnz short $+8
        mov ax,0x31cb
        jmp short $+6
        nop
L87:
        mov ax,0x31d0
L8A:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
LAE:
        mov ax,0x1
        jmp L231
        nop
LB5:
        mov ax,0x31c7
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0xe
        jmp short $+43
LD1:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+38
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
LFA:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $-89
L109:
        call far ptr helper_4
        mov [bp-0x2],ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xc
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x1388
        push ax
        call far ptr helper_5
        add sp,0x2
        mov byte ptr mb31C2,0x0
        cmp word ptr [bp-0x2],0x0
        jz short $+57
        cmp byte ptr mb034A,0x0
        jnz short $+50
        mov ax,0x5a0f
        push ax
        mov ax,0x3b5
        push ax
        call far ptr helper_6
        add sp,0x4
        mov byte ptr mb034A,0x1
        xor ax,ax
        push ax
        push ax
        mov cx,0x5
        push cx
        call far ptr helper_7
        add sp,0x6
        mov word ptr mn02CC,0x0
        call far ptr helper_8
L181:
        inc word ptr mn02CC
        cmp word ptr mn02CC,0x3
        jnl short $+5
        jmp LAE
L18F:
        cmp byte ptr mb034A,0x0
        jz short $+5
        jmp LAE
L199:
        mov byte ptr mb0351,0x1
        mov ax,0x5a0f
        push ax
        mov ax,0x3b7
        push ax
        call far ptr helper_6
        add sp,0x4
        call far ptr helper_8
        jmp LAE
        nop
L1B7:
        mov ax,0x11c
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+22
        mov ax,0x12
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp LAE
        nop
L1DF:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x13
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x6
        jmp LAE
L217:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        jmp LFA
L22F:
        xor ax,ax
L231:
    }
}
