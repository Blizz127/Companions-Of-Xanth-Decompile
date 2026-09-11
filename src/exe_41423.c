extern int __near mn69E4;
extern int __near mn69E6;
extern int __near mn0066;
extern int __near mn0050;
extern int __near mn0052;
extern int __near mn0062;
extern int __near mn0054;
extern int __near mn0060;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_41423(int a)
{
    _asm {
        sub sp,0x10
        mov ax,mn69E4
        mov [bp-0x2],ax
        mov cx,mn69E6
        mov [bp-0x4],cx
        cmp ax,0x33
        jl short $+52
        cmp cx,0x98
        jl short $+46
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x2
        cmp word ptr mn0066,0x0
        jz short $+39
        call far ptr helper_1
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x2
        mov word ptr mn0066,0x0
        jmp short $+14
L47:
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x2
L53:
        lea ax,[bp-0xa]
        push ss
        push ax
        lea cx,[bp-0x8]
        push ss
        push cx
        lea cx,[bp-0x6]
        push ss
        push cx
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        call far ptr helper_2
        add sp,0x10
        mov word ptr [bp-0xe],0x0
        mov word ptr [bp-0x10],0x0
        mov ax,[bp-0xa]
        sub ax,0x3
        jz short $+13
        sub ax,0x4
        jz short $+8
        dec ax
        jz short $+53
        jmp short $+70
        nop
L8D:
        cmp word ptr [bp-0x8],0x0
        jnz short $+24
        cmp word ptr mn0050,0x0
        jnz short $+17
        cmp word ptr mn0052,0x0
        jnz short $+10
        mov word ptr [bp-0x10],0x0
        jmp short $+42
        nop
LA9:
        push word ptr [bp-0x8]
        push word ptr [bp-0x6]
        call far ptr helper_3
        add sp,0x4
        mov [bp-0x10],ax
        jmp short $+22
        nop
LBD:
        lea ax,[bp-0x4]
        push ss
        push ax
        push word ptr [bp-0x8]
        call far ptr helper_4
        add sp,0x6
        mov [bp-0xe],ax
LD0:
        mov ax,mn0062
        cmp [bp-0x10],ax
        jz short $+29
        push word ptr [bp-0x10]
        xor ax,ax
        push ax
        push word ptr mn0054
        push word ptr mn0052
        push word ptr mn0050
        push ax
        call far ptr helper_5
        add sp,0xc
LF3:
        cmp word ptr mn0050,0x0
        jnz short $+55
        mov ax,mn0060
        cmp [bp-0xe],ax
        jz short $+47
        push word ptr [bp-0x4]
        push word ptr [bp-0xe]
        call far ptr helper_6
        add sp,0x4
        cmp word ptr mn0052,0x0
        jz short $+26
        xor ax,ax
        push ax
        push word ptr [bp-0xe]
        push word ptr mn0054
        push word ptr mn0052
        push word ptr mn0050
        push ax
        call far ptr helper_5
L12F:
        mov ax,[bp-0xe]
        mov mn0060,ax
        mov ax,[bp-0x10]
        mov mn0062,ax
    }
}
