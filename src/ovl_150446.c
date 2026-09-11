extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb2A2F;
extern char __near mb2A2E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_150446(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L1C7
L0E:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LFF
L19:
        jna short $+5
        jmp L1C7
L1E:
        sub al,0x8
        jz short $+27
        sub al,0xb
        jnz short $+5
        jmp LB1
L29:
        sub al,0xe
        jnz short $+5
        jmp LFF
L30:
        sub al,0xb
        jnz short $+5
        jmp L127
L37:
        jmp L1C7
        nop
L3B:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+38
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x8
L64:
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp short $+57
L73:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x9
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov byte ptr mb2A2F,0x1
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
LAA:
        mov ax,0x1
        jmp L1C9
        nop
LB1:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x5
        mov dx,0xf019
        jmp short $+7
LCD:
        mov ax,0x2a30
        mov dx,ds
LD2:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x4
LEF:
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp short $-82
        nop
LFF:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        cmp word ptr mn6A06,0x45
        jnz short $+7
        mov ax,0x2a3c
        jmp short $+5
L11D:
        mov ax,0x2a44
L120:
        push ds
        push ax
        mov ax,0xa
        jmp short $-54
L127:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
        jmp L64
L153:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x7
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov byte ptr mb2A2E,0x1
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        mov ax,0x12
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp LAA
L1A1:
        mov ax,0x12
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_5
        add sp,0x6
        jmp LAA
L1C7:
        xor ax,ax
L1C9:
    }
}
