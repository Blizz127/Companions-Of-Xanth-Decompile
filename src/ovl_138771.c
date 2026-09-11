extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb0314;
extern char __near mb0313;
extern char __near mb290E;
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
int far ovl_138771(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L27B
L0E:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L25F
L19:
        jna short $+5
        jmp L27B
L1E:
        sub al,0x8
        jz short $+27
        sub al,0xb
        jnz short $+5
        jmp LCF
L29:
        sub al,0x19
        jnz short $+5
        jmp L18B
L30:
        sub al,0x18
        jnz short $+5
        jmp L251
L37:
        jmp L27B
        nop
L3B:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+8
        mov ax,0xc
        jmp L17E
L55:
        mov ax,0xd
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xe
        push ax
        mov ax,0x9e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+50
        mov ax,0xe
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xe
        push ax
        mov ax,0x9e
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x2c
        push ax
        mov ax,0x9e
        push ax
        call far ptr helper_3
        add sp,0x4
LA9:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_3
LC6:
        add sp,0x4
LC9:
        mov ax,0x1
        jmp L27D
LCF:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2928
        jmp short $+6
        nop
LE9:
        mov ax,0x292f
LEC:
        push ds
        push ax
        mov ax,0x5
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+69
        cmp byte ptr mb0314,0x0
        jz short $+10
        mov ax,0x2937
        mov dx,ds
        jmp short $+9
        nop
L121:
        mov ax,0x7
        mov dx,0xf010
L127:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0xa0
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_4
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
        jmp LC9
        nop
L155:
        mov ax,0x2941
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xe
        push ax
        mov ax,0x9e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+7
        mov ax,0x8
        jmp short $+5
L17B:
        mov ax,0x9
L17E:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        jmp LC6
L18B:
        cmp byte ptr mb0314,0x0
        jnz short $+65
        mov byte ptr mb0313,0x1
        mov ax,0xb
        push ax
        call far ptr helper_5
        add sp,0x2
        mov ax,0x600
        push ax
        mov ax,0x308
        push ax
        call far ptr helper_6
        add sp,0x4
        cmp byte ptr mb0314,0x0
        jnz short $+5
        jmp LC9
L1BD:
        xor ax,ax
        push ax
        push ax
        mov ax,0xc
        push ax
        call far ptr helper_7
        add sp,0x6
        jmp LC9
        nop
L1D1:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+86
        call far ptr helper_8
        call far ptr helper_9
        mov byte ptr mb290E,0x0
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_10
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_4
        add sp,0x4
        push dx
        push ax
        mov ax,0xa
L229:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp LC9
L239:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_4
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        jmp short $-37
        nop
L251:
        xor ax,ax
        push ax
        mov ax,0xa0
        push ax
        push word ptr mn6A06
        jmp short $+21
        nop
L25F:
        cmp byte ptr mb0314,0x0
        jnz short $-19
        xor ax,ax
        push ax
        push word ptr mn6A04
        mov ax,0x2c
        push ax
L271:
        call far ptr helper_11
        add sp,0x6
        jmp short $+4
L27B:
        xor ax,ax
L27D:
    }
}
