extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb31C2;
extern char __near mb0349;
extern int __near mn02CA;
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
int far ovl_204367(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+40
        jmp L235
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L235
L1E:
        mov ax,0xd
L21:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
L2E:
        mov ax,0x1
        jmp L237
        nop
L35:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L22F
L40:
        jna short $+5
        jmp L235
L45:
        cmp al,0x2c
        jz short $+78
        ja short $+14
        sub al,0x8
        jz short $+24
        sub al,0xb
        jz short $+44
        jmp L235
        nop
L57:
        sub al,0x2f
        jz short $+120
        sub al,0x15
        jnz short $+5
        jmp L1AB
L62:
        jmp L235
L65:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x7
        jmp L1D4
L7D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x5
        jmp L1D4
L95:
        push word ptr mn6A04
        mov ax,0x26
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x31c3
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x6
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        jmp L2E
LD1:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
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
        jmp L1D4
LFD:
        call far ptr helper_3
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
        call far ptr helper_0
        add sp,0x8
        mov ax,0x1388
        push ax
        call far ptr helper_4
        add sp,0x2
        mov byte ptr mb31C2,0x0
        cmp word ptr [bp-0x2],0x0
        jz short $+57
        cmp byte ptr mb0349,0x0
        jnz short $+50
        mov ax,0x5a0f
        push ax
        mov ax,0x3b3
        push ax
        call far ptr helper_5
        add sp,0x4
        mov byte ptr mb0349,0x1
        xor ax,ax
        push ax
        push ax
        mov cx,0x5
        push cx
        call far ptr helper_6
        add sp,0x6
        mov word ptr mn02CA,0x0
        call far ptr helper_7
L175:
        inc word ptr mn02CA
        cmp word ptr mn02CA,0x3
        jnl short $+5
        jmp L2E
L183:
        cmp byte ptr mb0349,0x0
        jz short $+5
        jmp L2E
L18D:
        mov byte ptr mb0351,0x1
        mov ax,0x5a0f
        push ax
        mov ax,0x3b7
        push ax
        call far ptr helper_5
        add sp,0x4
        call far ptr helper_7
        jmp L2E
        nop
L1AB:
        mov ax,0x11c
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+40
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x9
L1D4:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L2E
        nop
L1E5:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x6
        jmp L2E
L22F:
        mov ax,0x8
        jmp L21
L235:
        xor ax,ax
L237:
    }
}
