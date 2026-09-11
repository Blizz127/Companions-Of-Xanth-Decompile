extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb034B;
extern char __near mb31C2;
extern int __near mn02CE;
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
int far ovl_205509(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+40
        jmp L1F1
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L1F1
L1E:
        mov ax,0x121
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_0
        add sp,0x6
        jmp L1F3
L35:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1EB
L40:
        jna short $+5
        jmp L1F1
L45:
        cmp al,0x2c
        jz short $+30
        ja short $+14
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+60
        jmp L1F1
        nop
L57:
        sub al,0x2f
        jz short $+76
        sub al,0x15
        jnz short $+5
        jmp L18B
L62:
        jmp L1F1
L65:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
L7A:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
L87:
        mov ax,0x1
        jmp L1F3
L8D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        jmp short $-40
        nop
LA5:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        jmp short $-84
        nop
LD1:
        cmp byte ptr mb034B,0x1
        sbb ax,ax
        neg ax
        push ax
        call far ptr helper_4
        add sp,0x2
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
        cmp word ptr [bp-0x2],0x2
        jng short $+57
        cmp byte ptr mb034B,0x0
        jnz short $+50
        mov ax,0x5a0f
        push ax
        mov ax,0x3b6
        push ax
        call far ptr helper_6
        add sp,0x4
        mov byte ptr mb034B,0x1
        xor ax,ax
        push ax
        push ax
        mov cx,0x5
        push cx
        call far ptr helper_7
        add sp,0x6
        mov word ptr mn02CE,0x0
        call far ptr helper_8
L156:
        inc word ptr mn02CE
        cmp word ptr mn02CE,0x3
        jnl short $+5
        jmp L87
L164:
        cmp byte ptr mb034B,0x0
        jz short $+5
        jmp L87
L16E:
        mov byte ptr mb0351,0x1
        mov ax,0x5a0f
        push ax
        mov ax,0x3b7
        push ax
        call far ptr helper_6
        add sp,0x4
        call far ptr helper_8
        jmp L87
L18B:
        mov ax,0x11b
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+22
        mov ax,0x17
L1A2:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L87
        nop
L1B3:
        push word ptr mn6A04
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
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
        jmp L87
L1EB:
        mov ax,0x16
        jmp short $-76
        nop
L1F1:
        xor ax,ax
L1F3:
    }
}
