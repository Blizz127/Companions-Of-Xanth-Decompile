extern int __near mn5D7C;
extern int __near mn5D7E;
extern int __near mn5D7A;
extern int __near mn5D78;
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
int far exe_63018(int a)
{
    _asm {
        sub sp,0x8
        xor ax,ax
        mov [bp-0x6],ax
        les bx, [bp+0x8]
        mov es:[bx],ax
        call far ptr helper_0
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        call far ptr helper_1
        or ax,ax
        jz short $+9
        call far ptr helper_2
        jmp short $+4
L29:
        xor ax,ax
L2B:
        cmp ax,0x3
        jnz short $+5
        jmp L15F
L33:
        cmp ax,0x1b
        jnz short $+5
        jmp L15F
L3B:
        mov ax,mn5D7C
        mov dx,mn5D7E
        cmp [bp-0x2],dx
        jnl short $+5
        jmp L174
L4A:
        jg short $+10
        cmp [bp-0x4],ax
        ja short $+5
        jmp L174
L54:
        mov ax,[bp+0x8]
        mov dx,[bp+0xa]
        add ax,0x6
        push dx
        push ax
        mov ax,[bp+0x8]
        add ax,0x4
        push dx
        push ax
        mov ax,[bp+0x8]
        add ax,0x2
        push dx
        push ax
        push dx
        push word ptr [bp+0x8]
        mov ax,0x5d7c
        push ds
        push ax
        mov cx,0x4
        mov dx,0xf001
        push dx
        push cx
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        push word ptr mn5D7A
        push word ptr mn5D78
        call far ptr helper_4
        add sp,0x1c
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        add mn5D7C,ax
        adc mn5D7E,dx
        cmp word ptr [bp+0x6],0x8
        jnz short $+23
        les bx, [bp+0x8]
        cmp word ptr es:[bx],0x2
        jnz short $+14
        cmp word ptr es:[bx+0x6],0x0
        jnz short $+7
        mov word ptr es:[bx],0x8
LC3:
        les bx, [bp+0x8]
        mov ax,es:[bx]
        mov cx,ax
        and ax,[bp+0x6]
        cmp ax,0x1
        sbb ax,ax
        inc ax
        mov [bp-0x6],ax
        test cl,0xe
        jz short $+47
        push word ptr es:[bx+0x4]
        push word ptr es:[bx+0x2]
        call far ptr helper_5
        add sp,0x4
        les bx, [bp+0x8]
        test byte ptr es:[bx],0x4
        jz short $+129
        push word ptr es:[bx+0x4]
        push word ptr es:[bx+0x2]
        call far ptr helper_6
L102:
        add sp,0x4
        jmp short $+111
        nop
        nop
L109:
        cmp word ptr es:[bx],0x4000
        jnz short $+61
        push word ptr mn5D7A
        push word ptr mn5D78
        mov ax,0x400
        push ax
        mov ax,0x1596
        mov cx,0x3420
        push cx
        push ax
        call far ptr helper_7
        add sp,0xa
        mov ax,0x1596
        mov cx,0x3420
        push cx
        push ax
        call far ptr helper_8
        add sp,0x4
        mov ax,0x1596
        mov cx,0x3420
        push cx
        push ax
        call far ptr helper_9
        jmp short $-71
L14B:
        cmp word ptr es:[bx],0x8000
        jz short $+31
        les bx, mn5D78
        test byte ptr es:[bx+0xa],0x10
        jz short $+25
        jmp short $+18
L15F:
        mov ax,0x3
        mov dx,0xf001
        push dx
        push ax
        call far ptr helper_9
        add sp,0x4
L16F:
        call far ptr helper_10
L174:
        mov ax,[bp-0x6]
    }
}
