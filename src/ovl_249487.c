extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb034F;
extern char __near mb034D;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_249487(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+124
        jmp L261
        nop
L13:
        mov ax,mn6A06
        dec ax
        dec ax
        jz short $+10
        sub ax,0x36
        jz short $+5
        jmp L261
L22:
        cmp word ptr mn6A04,0x138
        jnz short $+21
        mov ax,0x2b
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $+73
        nop
L3D:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
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
        mov ax,0x2c
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x10
L83:
        mov ax,0x1
        jmp L263
L89:
        mov ax,mn6A06
        cmp ax,0x4c
        jnz short $+5
        jmp L175
L94:
        jna short $+5
        jmp L261
L99:
        cmp al,0x38
        jnz short $+5
        jmp L21B
LA0:
        ja short $+23
        sub al,0x8
        jz short $+40
        sub al,0xb
        jnz short $+5
        jmp L131
LAD:
        sub al,0x19
        jnz short $+5
        jmp L175
LB4:
        jmp L261
LB7:
        sub al,0x44
        jnz short $+5
        jmp L21B
LBE:
        dec al
        jnz short $+5
        jmp L249
LC5:
        sub al,0x6
        jz short $+5
        jmp L261
LCC:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+27
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x27
        jmp L19E
        nop
LF9:
        mov ax,0x28
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        mov ax,0x4c
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov byte ptr mb034F,0x1
        jmp L83
L131:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x23
        jmp short $+6
        nop
L14B:
        mov ax,0x24
L14E:
        mov dx,0xf026
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x3417
        push ds
L169:
        push ax
        call far ptr helper_0
        add sp,0xc
        jmp L83
L175:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+40
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x25
L19E:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L83
        nop
L1AF:
        mov ax,0x126
        push ax
        mov ax,0x12e
        push ax
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x3426
        mov dx,ds
        jmp short $+6
        nop
L1CB:
        xor ax,ax
        cwd
L1CE:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x26
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0x4b
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        mov ax,0x3429
        push ds
        push ax
        call far ptr helper_7
        add sp,0x4
        mov byte ptr mb034D,0x1
        jmp L83
L21B:
        mov ax,0x128
        push ax
        mov ax,0x22
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
        mov ax,0x29
        mov dx,0xf026
        push dx
        jmp L169
L249:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x2a
        jmp L19E
L261:
        xor ax,ax
L263:
    }
}
