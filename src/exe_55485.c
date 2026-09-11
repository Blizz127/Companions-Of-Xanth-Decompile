extern int __near mn24I;
extern int __near mn5A38;
extern int __near mn0266;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_55485(int a)
{
    _asm {
        sub sp,0xa
        mov word ptr [bp-0x2],0x0
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x4],ax
        mov bx,[bp+0x6]
        mov ax,bx
        add bx,bx
        add bx,ax
        add bx,bx
        add bx, offset mn24I
        mov es, mn5A38
        mov [bp-0xa],bx
        mov word ptr [bp-0x8],es
        cmp byte ptr es:[bx],0x1
        jnz short $+34
        cmp word ptr [bp-0x4],0x0
        jz short $+28
lbl3E:
        mov ax,mn0266
        cmp [bp-0x4],ax
        jnz short $+20
        push word ptr [bp-0x4]
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x4],ax
        or ax,ax
        jnz short $-24
lbl58:
        cmp word ptr [bp-0x4],0x0
        jz short $+124
lbl5E:
        push word ptr [bp-0x4]
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x6],ax
        les bx, [bp-0xa]
        cmp byte ptr es:[bx],0x1
        jnz short $+32
        or ax,ax
        jz short $+28
lbl79:
        mov ax,mn0266
        cmp [bp-0x4],ax
        jnz short $+20
        push word ptr [bp-0x6]
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x6],ax
        or ax,ax
        jnz short $-24
lbl93:
        cmp word ptr [bp-0x2],0x0
        jng short $+37
        cmp word ptr [bp-0x6],0x0
        jz short $+18
        mov ax,0x2c
        push ax
        call far ptr helper_2
        add sp,0x2
        jmp short $+17
        nop
        nop
lblAF:
        mov ax,0x1f3
        push ds
        push ax
        call far ptr helper_3
        add sp,0x4
lblBC:
        inc word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x83
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,[bp-0x6]
        mov [bp-0x4],ax
        or ax,ax
        jnz short $-120
lblD8:
        mov ax,[bp-0x2]
    }
}
