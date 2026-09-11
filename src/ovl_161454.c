extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb030D;
extern int __near mn02A6;
extern char __near mb031D;
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
int far ovl_161454(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LE1
L0F:
        jmp L265
        nop
L13:
        mov ax,mn6A06
        sub ax,0x19
        jz short $+5
        jmp L265
L1E:
        mov ax,mn6A04
        sub ax,0x88
        jl short $+26
        jo short $+24
        dec ax
        jng short $+42
        sub ax,0x12
        jnz short $+5
        jmp LBB
L33:
        sub ax,0x9
        jl short $+8
        dec ax
        jg short $+5
        jmp LD7
L3E:
        mov ax,0x64e
        push ax
        mov ax,0x359
L45:
        push ax
        call far ptr helper_0
        mov sp,bp
L4D:
        mov ax,0x1
        jmp L267
L53:
        mov ax,0x1
        push ax
        mov ax,0x88
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+69
        mov ax,0x1
        push ax
        mov ax,0x89
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+50
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        cmp ax,0x147
        jnz short $+12
        mov ax,0x64e
        push ax
        mov ax,0x356
        jmp short $-75
        nop
L93:
        xor ax,ax
        push ax
        push word ptr mn6A02
L9A:
        mov ax,0x45
        push ax
        call far ptr helper_3
        add sp,0x6
        jmp L267
LA9:
        mov ax,0x64e
        push ax
        mov ax,0x358
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $-108
LBB:
        call far ptr helper_4
        or ax,ax
        jz short $+11
        xor ax,ax
        push ax
        mov ax,0xd
        push ax
        jmp short $-49
LCD:
        mov ax,0x64e
        push ax
        mov ax,0x355
        jmp L45
LD7:
        mov ax,0x64e
        push ax
        mov ax,0x35a
        jmp L45
LE1:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+81
        jmp L265
LF1:
        mov ax,0x33
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_5
        add sp,0x4
        push word ptr mn6A04
        mov ax,0xbd
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L4D
L118:
        mov ax,0xbd
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_6
        add sp,0x4
        push dx
        push ax
        mov ax,0x34
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_5
        add sp,0x8
        jmp L4D
L13D:
        cmp byte ptr mb030D,0x0
        jz short $+13
        mov ax,0x64e
        push ax
        mov ax,0x32b
        jmp L45
        nop
L14F:
        cmp word ptr mn02A6,0x2
        jnz short $+13
        mov ax,0x64e
        push ax
        mov ax,0x32c
        jmp L45
        nop
L161:
        call far ptr helper_4
        or ax,ax
        jz short $+107
        mov ax,0x1
        push ax
        mov ax,0x88
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+59
        mov ax,0x1
        push ax
        mov ax,0x89
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+39
        mov ax,0x88
        push ax
        call far ptr helper_2
        add sp,0x2
        cmp ax,0x147
        jz short $+12
        mov ax,0x64e
        push ax
        mov ax,0x336
        jmp L45
L1AD:
        mov ax,0x64e
        push ax
        mov ax,0x354
        jmp L45
L1B7:
        cmp byte ptr mb031D,0x0
        jnz short $+13
        mov ax,0x64e
        push ax
        mov ax,0x33d
        jmp L45
        nop
L1C9:
        mov ax,0x64e
        push ax
        mov ax,0x33e
        jmp L45
L1D3:
        mov ax,0x1
        push ax
        mov ax,0xbd
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+12
        mov ax,0x64e
        push ax
        mov ax,0x33f
        jmp L45
L1F1:
        mov ax,0x64e
        push ax
        mov ax,0x340
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0xbd
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L4D
L218:
        mov ax,0xa
        push ax
        mov ax,0xb8
        push ax
        call far ptr helper_7
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L4D
L22F:
        mov ax,0xa
        push ax
        mov ax,0xb8
        push ax
        call far ptr helper_8
        add sp,0x4
        mov ax,0x35
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_5
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x8
        push ax
        call far ptr helper_9
        add sp,0x6
        jmp L4D
L265:
        xor ax,ax
L267:
    }
}
