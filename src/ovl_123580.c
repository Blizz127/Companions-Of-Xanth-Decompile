extern int __near mn6A06;
extern char __near mb02F3;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_123580(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+40
        jmp L32F
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L32F
L1E:
        mov ax,0x56
L21:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
L2B:
        add sp,0x4
L2E:
        mov ax,0x1
        jmp L331
        nop
L35:
        mov ax,mn6A06
        cmp ax,0x4d
        jnz short $+5
        jmp L2A3
L40:
        jna short $+5
        jmp L32F
L45:
        cmp al,0x25
        jnz short $+5
        jmp L153
L4C:
        ja short $+21
        sub al,0x7
        jz short $+41
        dec al
        jz short $+69
        sub al,0xb
        jnz short $+5
        jmp LEB
L5D:
        jmp L32F
        nop
L61:
        sub al,0x2c
        jnz short $+5
        jmp L1FD
L68:
        sub al,0x18
        jnz short $+5
        jmp L285
L6F:
        dec al
        jnz short $+5
        jmp L29D
L76:
        jmp L32F
L79:
        cmp byte ptr mb02F3,0x0
        jz short $+7
        xor ax,ax
        cwd
        jmp short $+7
L85:
        mov ax,0x26d5
        mov dx,ds
L8A:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x55
        jmp L2EC
        nop
L99:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x4c
        jmp L2EC
LC5:
        mov ax,0x4d
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        mov ax,0x2c
        jmp L278
LEB:
        mov ax,0x46
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x26b0
        jmp short $+39
        nop
L115:
        mov ax,0x26ba
        push ds
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+15
        mov ax,0x26c9
L139:
        push ds
        push ax
        call far ptr helper_0
        add sp,0x4
L143:
        mov ax,0x2e
        push ax
        call far ptr helper_4
        add sp,0x2
        jmp L2E
        nop
L153:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x4e
        jmp L2EC
L17F:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x4f
        jmp L2EC
L1AB:
        cmp word ptr mn6A02,0x93
        jz short $+26
        push word ptr mn6A02
        mov ax,0x3
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x50
        jmp L2EC
L1CB:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x51
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        jmp L2B
L1FD:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x49
        jmp L2EC
L229:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x4a
        jmp L2EC
L255:
        mov ax,0x4b
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x8
L278:
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        jmp L2B
L285:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x47
        jmp short $+82
        nop
L29D:
        mov ax,0x48
        jmp L21
L2A3:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x52
        jmp short $+32
        nop
L2CF:
        cmp word ptr mn6A02,0x93
        jz short $+40
        push word ptr mn6A02
        mov ax,0x3
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x53
L2EC:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L2E
        nop
L2FD:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x54
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        jmp L2B
L32F:
        xor ax,ax
L331:
    }
}
