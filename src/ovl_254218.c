extern int __near mn6A06;
extern int __near mn6A04;
extern char __near mb3480;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_254218(int a)
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
        jmp L275
L19:
        jna short $+5
        jmp L27B
L1E:
        cmp al,0x2c
        jnz short $+5
        jmp LB7
L25:
        ja short $+14
        sub al,0x8
        jz short $+28
        sub al,0xb
        jz short $+46
        jmp L27B
        nop
L33:
        sub al,0x3b
        jnz short $+5
        jmp LD3
L3A:
        sub al,0x9
        jnz short $+5
        jmp LD3
L41:
        jmp L27B
        nop
L45:
        mov ax,0x18
L48:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
L55:
        mov ax,0x1
        jmp L27D
L5B:
        mov ax,0x13
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x2
        dec ax
        jz short $+15
        sub ax,0x127
        jz short $+18
        sub ax,0xf
        jz short $+21
        jmp short $+29
        nop
L87:
        mov word ptr [bp-0x4],0x15
        jmp short $+16
        nop
L8F:
        mov word ptr [bp-0x4],0x16
        jmp short $+8
        nop
L97:
        mov word ptr [bp-0x4],0x14
L9C:
        mov word ptr [bp-0x2],0xf027
LA1:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x348c
        push ds
LAB:
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp short $-95
        nop
LB7:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
LCC:
        mov dx,0xf027
        push dx
        jmp short $-37
        nop
LD3:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x1a
        jmp L48
LED:
        mov ax,0x137
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L1E3
L104:
        mov ax,0xa
        push ax
        mov ax,0x137
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+57
        mov ax,0x137
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        jmp L55
L14F:
        mov ax,0x137
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x6
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0xa
        push ax
        mov ax,0x132
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L55
L1BD:
        mov ax,0xa
        push ax
        mov ax,0x132
        push ax
        call far ptr helper_6
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_7
        add sp,0x6
        jmp L55
L1E3:
        mov ax,0x128
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L55
L1FA:
        mov ax,0x126
        push ax
        mov ax,0x12e
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+81
        mov ax,0x128
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_0
        add sp,0xc
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x6
        mov byte ptr mb3480,0x0
        jmp L55
L25D:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
        jmp LCC
L275:
        mov ax,0x19
        jmp L48
L27B:
        xor ax,ax
L27D:
    }
}
