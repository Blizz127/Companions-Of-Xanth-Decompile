extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn02AA;
extern int __near mn5AC6;
extern int __near mn6A02;
extern int __near mn0256;
extern char __near mb036E;
extern int __near mn0798;
extern int __near mn0290;
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
void far helper_10(void);
void far helper_11(void);
void far helper_12(void);
void far helper_13(void);
int far ovl_117879(int a)
{
    _asm {
        sub sp,0x6
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L34B
L0E:
        mov ax,mn6A06
        cmp ax,0x47
        jnz short $+5
        jmp L20F
L19:
        jna short $+5
        jmp L34B
L1E:
        cmp al,0x38
        jnz short $+5
        jmp L115
L25:
        ja short $+18
        sub al,0x8
        jz short $+38
        sub al,0xb
        jz short $+74
        sub al,0x19
        jz short $+30
        jmp L34B
        nop
L37:
        sub al,0x43
        jnz short $+5
        jmp L1A5
L3E:
        dec al
        jnz short $+5
        jmp L1BD
L45:
        dec al
        jnz short $+5
        jmp L1D1
L4C:
        jmp L34B
L4F:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x5e
L64:
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L71:
        mov ax,0x1
        jmp L34D
L77:
        mov ax,0x58
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        cmp word ptr mn02AA,0x0
        jz short $-27
        mov ax,0x59
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn02AA,0x0
        jng short $+94
        mov word ptr [bp-0x6],0xe4
LAF:
        mov es, mn5AC6
        mov bx,[bp-0x6]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        mov ax,0x265f
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        cmp word ptr mn02AA,0x1
        jng short $+40
        mov ax,mn02AA
        sub ax,[bp-0x2]
        cmp ax,0x2
        jnz short $+7
        mov ax,0x2668
        jmp short $+14
LE1:
        mov ax,mn02AA
        sub ax,[bp-0x2]
        dec ax
        jz short $+15
        mov ax,0x266e
LED:
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
LF7:
        add word ptr [bp-0x6],0x4
        mov ax,mn02AA
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-85
L106:
        mov ax,0x2e
        push ax
        call far ptr helper_2
L10F:
        add sp,0x2
        jmp L71
L115:
        mov ax,mn6A02
        sub ax,0xc4
        jz short $+114
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+30
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+10
        mov word ptr [bp-0x4],0x6f
        jmp short $+8
        nop
L14D:
        mov word ptr [bp-0x4],0x69
L152:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0x4]
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x60
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
        add sp,0xe
        jmp L71
        nop
L18D:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x5f
        jmp L64
L1A5:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x63
        jmp L64
L1BD:
        mov ax,0x62
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
L1CA:
        add sp,0x4
        jmp L71
        nop
L1D1:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2671
        jmp short $+6
        nop
L1EB:
        mov ax,0x267f
L1EE:
        push ds
        push ax
        mov ax,0x61
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        jmp short $-67
L20F:
        cmp word ptr mn0256,0x1f0
        jz short $+5
        jmp L301
L21A:
        cmp word ptr mn6A02,0x1f2
        jz short $+13
        cmp word ptr mn6A02,0x1f1
        jz short $+5
        jmp L301
L22D:
        mov ax,0x2b
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0x5a
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
        push ax
        push ax
        mov cx,0x19
        push cx
        call far ptr helper_6
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0x8b
        push cx
        call far ptr helper_7
        add sp,0x6
        xor ax,ax
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0xb
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x20
        push ax
        call far ptr helper_9
        add sp,0x2
        xor al,al
        push ax
        mov ax,0x7
        push ax
        mov ax,0x1240
        push ax
        call far ptr helper_10
        add sp,0x6
        mov ax,0xbb8
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x5b
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_11
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0x1247
        push ax
        call far ptr helper_12
        add sp,0x4
        mov ax,0x1f40
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x5c
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_11
        add sp,0x4
        mov byte ptr mb036E,0x1
        xor ax,ax
        mov mn0798,ax
        mov mn0290,ax
        mov ax,0x22
        push ax
        call far ptr helper_13
        jmp L10F
L301:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn0290
        mov ax,0x11
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x5d
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x10
        jmp L71
        nop
L34B:
        xor ax,ax
L34D:
    }
}
