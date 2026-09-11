extern char __near mb6E5C;
extern int __near mn02DA;
extern char __near mb36D2;
extern char __near mb0372;
void far helper_0(void);
void far helper_1(void);
int far if15_284655(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0xf
        jz short $+62
        mov al,mb6E5C
        sub ah,ah
        sub ax,0x6
        jz short $+12
        sub ax,0x3
        jz short $+21
        dec ax
        jz short $+34
        jmp short $+26
L1D:
        cmp word ptr mn02DA,0x1
        sbb ax,ax
        and ax,0x170
        jmp L140
        nop
L2B:
        cmp word ptr mn02DA,0x3
        jnl short $+5
        jmp L13D
L35:
        xor ax,ax
        jmp L140
        nop
L3B:
        cmp word ptr mn02DA,0x0
        jng short $-11
        jmp L13D
L45:
        mov al,mb6E5C
        sub ah,ah
        sub ax,0x6
        jz short $+16
        sub ax,0x3
        jz short $+47
        dec ax
        jnz short $+5
        jmp LED
L5A:
        jmp short $-37
        nop
L5D:
        cmp word ptr mn02DA,0x0
        jnz short $+25
        mov ax,0x22
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x170
        jmp L140
        nop
L7B:
        mov ax,0xffff
        jmp L140
L81:
        cmp word ptr mn02DA,0x3
        jnz short $+21
        mov ax,0x1d
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $-99
        nop
L9B:
        inc word ptr mn02DA
        mov ax,0x1e
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        cmp word ptr mn02DA,0x3
        jnl short $+21
        mov ax,0x1f
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        jmp short $+24
        nop
LC9:
        mov ax,0x20
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov byte ptr mb36D2,0x0
LDE:
        mov ax,0x371f
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $+82
LED:
        cmp word ptr mn02DA,0x0
        jz short $-119
        dec word ptr mn02DA
        cmp byte ptr mb0372,0x0
        jz short $+10
        mov ax,0x3728
        mov dx,ds
        jmp short $+6
        nop
L107:
        xor ax,ax
        cwd
L10A:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x21
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov byte ptr mb0372,0x1
        cmp word ptr mn02DA,0x2
        jnz short $+7
        mov byte ptr mb36D2,0x0
L133:
        mov ax,0x372f
        push ds
        push ax
        call far ptr helper_1
L13D:
        mov ax,0x174
L140:
    }
}
