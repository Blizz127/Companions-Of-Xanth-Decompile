extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_155663(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+62
        jmp LB3
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LB3
L1E:
        mov ax,0x2ae9
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_0
        add sp,0x8
        push dx
        push ax
        mov ax,0x54
L38:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        jmp short $+109
        nop
L4B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+74
        ja short $+96
        sub al,0x13
        jz short $+8
        sub al,0x31
        jz short $+34
        jmp short $+86
L5F:
        cmp word ptr mn6A04,0x1d
        jnz short $+9
        mov ax,0x2ada
        mov dx,ds
        jmp short $+5
L6D:
        xor ax,ax
        cwd
L70:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x51
        jmp short $-67
L7D:
        cmp word ptr mn6A04,0x1d
        jnz short $+9
        mov ax,0x2ae3
        mov dx,ds
        jmp short $+5
L8B:
        xor ax,ax
        cwd
L8E:
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        push dx
        push ax
        mov ax,0x52
        jmp short $-97
L9B:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x53
        jmp short $-120
        nop
LB3:
        xor ax,ax
LB5:
    }
}
