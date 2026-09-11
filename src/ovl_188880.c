extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern int __near mn0256;
extern int __near mn0058;
extern int __near mn0056;
extern char __near mb0327;
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
int far ovl_188880(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp L141
L0F:
        jmp L1E9
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x9
        jz short $+5
        jmp L1E9
L23:
        mov ax,mn6A04
        sub ax,0x4d
        jz short $+52
        sub ax,0x29
        jnz short $+5
        jmp L12B
L33:
        push word ptr mn6A02
        mov ax,0x3
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x16
        jmp L12E
        nop
L5D:
        mov ax,0xa
        push ax
        mov ax,0xfa
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+9
        mov ax,0x11
        jmp L12E
        nop
L77:
        mov ax,0xe
        push ax
        mov ax,0x4d
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+9
        mov ax,0x12
        jmp L12E
        nop
L91:
        mov ax,0x13
        mov dx,0xf020
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0xa
        push ax
        mov ax,0xfa
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x152
        push ax
        push word ptr mn6A02
        call far ptr helper_4
        mov sp,bp
        cmp word ptr mn0256,0xfb
        jnz short $+118
        call far ptr helper_5
        mov ax,0x14
        mov dx,0xf020
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        push ax
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_6
        mov sp,bp
        cmp word ptr mn0058,0x0
        jnz short $+37
        cmp word ptr mn0056,0x1
        jz short $+30
        call far ptr helper_7
        mov al,0x1
        push ax
        mov ax,0x16
        push ax
        mov ax,0xa85
        push ax
        call far ptr helper_8
        mov sp,bp
        call far ptr helper_9
L114:
        xor ax,ax
        push ax
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_10
        mov sp,bp
        mov byte ptr mb0327,0x1
        jmp short $+18
        nop
L12B:
        mov ax,0x15
L12E:
        mov dx,0xf020
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
L13A:
        mov ax,0x1
        jmp L1EB
        nop
L141:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L1D1
L14C:
        jna short $+5
        jmp L1E9
L151:
        cmp al,0x13
        jz short $+42
        ja short $+14
        sub al,0x8
        jz short $+24
        sub al,0x7
        jz short $+26
        jmp L1E9
        nop
L163:
        sub al,0x2c
        jz short $+12
        sub al,0x13
        jz short $+58
        sub al,0x5
        jz short $+94
        jmp short $+122
L171:
        mov ax,0xd
        jmp short $-70
        nop
L177:
        mov ax,0x10
        jmp short $-76
        nop
L17D:
        mov ax,0xa
        push ax
        mov ax,0xfa
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+11
        mov ax,0xb
        mov dx,0xf020
        jmp short $+6
        nop
L199:
        xor ax,ax
        cwd
L19C:
        push dx
        push ax
        mov ax,0xa
        jmp short $-115
L1A3:
        mov ax,0xa
        push ax
        mov ax,0xfa
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+11
        mov ax,0xb
        mov dx,0xf020
        jmp short $+6
        nop
L1BF:
        xor ax,ax
        cwd
L1C2:
        push dx
        push ax
        mov ax,0xf
        jmp L12E
        nop
L1CB:
        mov ax,0xc
        jmp L12E
L1D1:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
        jmp L12E
L1E9:
        xor ax,ax
L1EB:
    }
}
