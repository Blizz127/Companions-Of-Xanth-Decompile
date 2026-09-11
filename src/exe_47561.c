extern int __near mn5C38;
extern int __near mn00F4;
extern int __near mn5A2A;
extern int __near mn00F8;
extern int __near mn00FA;
extern int __near mn5C3A;
extern int __near mn5C3C;
extern int __near mn5C52;
extern int __near mn5C54;
extern int __near mn5C5A;
extern int __near mn5C56;
extern int __near mn5C58;
extern int __near mn5C4C;
extern int __near mn5C4A;
extern int __near mn5C46;
extern int __near mn5C48;
extern int __near mn5C4E;
extern int __near mn5C50;
extern int __near mn5C42;
extern int __near mn5C3E;
extern int __near mn5C40;
extern int __near mn5C44;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_47561(int a)
{
    _asm {
        sub sp,0x10e
        xor ax,ax
        push ax
        mov cx,0x270
        push ds
        push cx
        call far ptr helper_0
        add sp,0x6
        mov mn5C38,ax
        or ax,ax
        jnz short $+28
        mov ax,0x270
        push ds
        push ax
        mov ax,0x93e
        mov cx,0x21aa
        push cx
        push ax
        call far ptr helper_1
        add sp,0x8
        call far ptr helper_2
L35:
        push word ptr mn5C38
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        mov ax,0xf4
        push ds
        push ax
        call far ptr helper_3
        add sp,0xa
        push word ptr mn5C38
        push word ptr mn00F4
        mov ax,0x6
        push ax
        mov ax,0x100
        mov cx,0x21aa
        push cx
        push ax
        call far ptr helper_3
        add sp,0xa
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn00F4,0x0
        jz short $+54
        mov word ptr [bp-0x104],0x100
        mov ax,mn00F4
        mov [bp-0x106],ax
L83:
        mov bx,[bp-0x104]
        mov es, mn5A2A
        mov ax,es:[bx]
        mov [bp-0x10e],ax
        cmp ax,mn00F8
        jna short $+5
        mov mn00F8,ax
L9B:
        add mn00FA,ax
        add word ptr [bp-0x104],0x6
        dec word ptr [bp-0x106]
        jnz short $-37
LAA:
        mov ax,mn00F8
        add ax,ax
        push ax
        call far ptr helper_4
        add sp,0x2
        mov mn5C3A,ax
        mov mn5C3C,dx
        mov ax,dx
        or ax,mn5C3A
        jnz short $+23
        mov ax,0x926
        mov cx,0x21aa
        push cx
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
LDC:
        push word ptr mn5C38
        call far ptr helper_5
        add sp,0x2
        mov mn5C52,ax
        mov mn5C54,dx
        mov ax,mn00FA
        add ax,ax
        sub dx,dx
        push dx
        push ax
        mov ax,0x1
        push ax
        push word ptr mn5C38
        call far ptr helper_6
        add sp,0x8
        push word ptr mn5C38
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        mov ax,0x5c5a
        push ds
        push ax
        call far ptr helper_3
        add sp,0xa
        mov ax,mn5C5A
        add ax,ax
        push ax
        call far ptr helper_4
        add sp,0x2
        mov mn5C56,ax
        mov mn5C58,dx
        mov ax,dx
        or ax,mn5C56
        jnz short $+23
        mov ax,0x926
        mov cx,0x21aa
        push cx
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
L153:
        push word ptr mn5C38
        push word ptr mn5C5A
        mov ax,0x2
        push ax
        push word ptr mn5C58
        push word ptr mn5C56
        call far ptr helper_3
        add sp,0xa
        push word ptr mn5C38
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        mov ax,0x5c4c
        push ds
        push ax
        call far ptr helper_3
        add sp,0xa
        cmp word ptr mn5C4C,0x0
        jnz short $+5
        jmp L25F
L192:
        push word ptr mn5C38
        push word ptr mn5C4C
        mov ax,0x2
        push ax
        lea cx,[bp-0x102]
        push ss
        push cx
        call far ptr helper_3
        add sp,0xa
        push word ptr mn5C38
        mov ax,0x1
        push ax
        mov ax,0x2
        push ax
        mov ax,0x5c4a
        push ds
        push ax
        call far ptr helper_3
        add sp,0xa
        push word ptr mn5C4A
        call far ptr helper_4
        add sp,0x2
        mov mn5C46,ax
        mov mn5C48,dx
        mov ax,dx
        or ax,mn5C46
        jnz short $+23
        mov ax,0x926
        mov cx,0x21aa
        push cx
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
L1F5:
        push word ptr mn5C38
        push word ptr mn5C4A
        mov ax,0x1
        push ax
        push word ptr mn5C48
        push word ptr mn5C46
        call far ptr helper_3
        add sp,0xa
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn5C4C,0x0
        jz short $+68
        lea ax,[bp-0x102]
        mov [bp-0x108],ax
        mov word ptr [bp-0x10a],0x700
        mov ax,mn5C4C
        mov [bp-0x10c],ax
        mov es, mn5A2A
L236:
        mov bx,[bp-0x108]
        add word ptr [bp-0x108],0x2
        mov ax,[bx]
        add ax,mn5C46
        mov dx,mn5C48
        mov bx,[bp-0x10a]
        mov es:[bx],ax
        mov es:[bx+0x2],dx
        add word ptr [bp-0x10a],0x4
        dec word ptr [bp-0x10c]
        jnz short $-39
L25F:
        push word ptr mn5C38
        call far ptr helper_5
        add sp,0x2
        mov mn5C4E,ax
        mov mn5C50,dx
        mov word ptr mn5C42,0xc00
L278:
        push word ptr mn5C42
        call far ptr helper_4
        add sp,0x2
        mov mn5C3E,ax
        mov mn5C40,dx
        mov ax,dx
        or ax,mn5C3E
        jnz short $+16
        sub word ptr mn5C42,0x100
        cmp word ptr mn5C42,0x400
        jnc short $-39
L2A1:
        mov ax,dx
        or ax,mn5C3E
        jnz short $+23
        mov ax,0x926
        mov cx,0x21aa
        push cx
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
L2BE:
        xor ax,ax
        mov mn5C44,ax
    }
}
