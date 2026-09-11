extern int __near mn5E2E;
extern int __near mn4232;
extern int __near mn6D26;
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
void far helper_12(void);
int far ovl_241527(int a)
{
    _asm {
        sub sp,0x12
        mov ax,0xd
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0xffff
        push ax
        call far ptr helper_1
        add sp,0x2
        call far ptr helper_2
        or ax,ax
        jz short $+5
        jmp L13A
L27:
        push word ptr mn5E2E
        call far ptr helper_3
        add sp,0x2
        call far ptr helper_2
        or ax,ax
        jnz short $+25
L3C:
        call far ptr helper_4
        or ax,ax
        jnz short $+16
        call far ptr helper_5
        call far ptr helper_2
        or ax,ax
        jz short $-21
L53:
        call far ptr helper_2
        or ax,ax
        jz short $+5
        jmp L13A
L5F:
        mov [bp-0xe],ax
        cmp [bp+0xa],ax
        jg short $+5
        jmp L116
L6A:
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x12],ax
        mov [bp-0x10],dx
L76:
        mov ax,0x3633
        mov dx,0x1dc1
        push dx
        push ax
        push word ptr [bp-0x10]
        push word ptr [bp-0x12]
        call far ptr helper_6
        add sp,0x8
        cmp word ptr mn4232,0x0
        jnz short $+20
        call far ptr helper_7
        les bx, [bp-0x12]
        add ax,es:[bx+0x6]
        adc dx,0x0
        jmp short $+6
        nop
LA5:
        xor ax,ax
        cwd
LA8:
        mov [bp-0xc],ax
        mov [bp-0xa],dx
        lea ax,[bp-0x8]
        push ss
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_8
        add sp,0x6
        or ax,ax
        jnz short $+45
LC3:
        call far ptr helper_7
        cmp dx,[bp-0xa]
        jg short $+35
        jl short $+7
        cmp ax,[bp-0xc]
        jnc short $+28
LD4:
        call far ptr helper_5
        lea ax,[bp-0x8]
        push ss
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_8
        add sp,0x6
        or ax,ax
        jz short $-41
LEE:
        call far ptr helper_9
        call far ptr helper_10
        cmp word ptr [bp-0x8],0x1
        jnz short $+8
        cmp word ptr [bp-0x2],0x1b
        jz short $+20
L104:
        add word ptr [bp-0x12],0x10
        mov ax,[bp+0xa]
        inc word ptr [bp-0xe]
        cmp [bp-0xe],ax
        jnl short $+5
        jmp L76
L116:
        mov word ptr mn6D26,0x3f
        call far ptr helper_2
        or ax,ax
        jnz short $+23
L125:
        cmp word ptr mn6D26,0x0
        jl short $+16
        call far ptr helper_5
        call far ptr helper_2
        or ax,ax
        jz short $-19
L13A:
        call far ptr helper_9
        call far ptr helper_11
        call far ptr helper_12
        cmp ax,0x1b
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L153:
        xor ax,ax
L155:
    }
}
