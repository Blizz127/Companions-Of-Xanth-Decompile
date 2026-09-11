extern int __near mn57F0;
extern int __near mn57F2;
extern int __near mn57F4;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_15836(int a)
{
    _asm {
        sub sp,0x8
        les bx, [bp+0x6]
        cmp word ptr es:[bx+0x2],0x0
        jnl short $+8
L0D:
        xor ax,ax
        cwd
        jmp L11F
L13:
        call far ptr helper_0
        les bx, [bp+0x6]
        mov ax,es:[bx]
        mov dx,es:[bx+0x2]
        sub ax,mn57F0
        sbb dx,mn57F2
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,dx
        jl short $+95
        lea cx,[bp-0x4]
        push ss
        push cx
        call far ptr helper_1
        add sp,0x4
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        cmp word ptr mn57F4,0x0
        jnz short $+5
        jmp L119
L51:
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L119
L62:
        add word ptr [bp-0x4],0xe10
        adc word ptr [bp-0x2],0x0
        cmp word ptr [bp-0x2],0x0
        jl short $-98
        lea ax,[bp-0x4]
        push ss
        push ax
        call far ptr helper_1
        add sp,0x4
        mov es,dx
        mov bx,ax
        mov [bp-0x8],ax
        mov word ptr [bp-0x6],es
        mov word ptr es:[bx+0x10],0x1
        jmp L119
L91:
        add ax,0x5180
        adc dx,0x1
        or dx,dx
        jl short $+64
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        lea ax,[bp-0x4]
        push ss
        push ax
        call far ptr helper_1
        add sp,0x4
        mov es,dx
        mov bx,ax
        mov [bp-0x8],ax
        mov word ptr [bp-0x6],es
        mov word ptr es:[bx+0xa],0x45
        mov word ptr es:[bx+0x8],0xb
        mov word ptr es:[bx+0x6],0x1f
        mov word ptr es:[bx+0xc],0x3
        mov word ptr es:[bx+0xe],0x16c
        jmp short $+67
        nop
LD9:
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        sub ax,0x5180
        sbb dx,0x1
        or dx,dx
        jl short $+50
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        lea ax,[bp-0x4]
        push ss
        push ax
        call far ptr helper_1
        mov es,dx
        mov bx,ax
        mov [bp-0x8],ax
        mov word ptr [bp-0x6],es
        inc word ptr es:[bx+0x6]
        mov ax,es:[bx+0xc]
        inc ax
        mov es:[bx+0xc],ax
        mov ax,es:[bx+0xe]
        inc ax
        mov es:[bx+0xe],ax
L119:
        mov ax,[bp-0x8]
        mov dx,[bp-0x6]
L11F:
    }
}
