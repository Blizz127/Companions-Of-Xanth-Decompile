extern int __near mn69F8;
extern int __near mn005A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_36252(int a)
{
    _asm {
        sub sp,0x12
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x2
        mov word ptr [bp-0xa],0x0
        call far ptr helper_1
        mov es,dx
        mov bx,ax
        cmp word ptr es:[bx],0x0
        jz short $+35
        mov [bp-0xe],ax
        mov [bp-0xc],dx
L29:
        mov ax,[bp+0x6]
        les bx, [bp-0xe]
        cmp es:[bx],ax
        jz short $+79
        inc word ptr [bp-0xa]
        add word ptr [bp-0xe],0x2
        mov bx,[bp-0xe]
        cmp word ptr es:[bx],0x0
        jnz short $-25
L44:
        mov word ptr [bp-0xa],0x0
        push word ptr [bp+0x8]
        call far ptr helper_2
        add sp,0x2
        mov es,dx
        mov bx,ax
        cmp word ptr es:[bx],0x0
        jz short $+63
        mov [bp-0x12],ax
        mov [bp-0x10],dx
L64:
        mov ax,[bp+0x6]
        les bx, [bp-0x12]
        cmp es:[bx],ax
        jz short $+32
        inc word ptr [bp-0xa]
        add word ptr [bp-0x12],0x2
        mov bx,[bp-0x12]
        cmp word ptr es:[bx],0x0
        jnz short $-25
        jmp short $+28
L81:
        mov ax,[bp-0xa]
        imul word ptr mn69F8
        add ax,0x4
        jmp short $+18
L8D:
        mov ax,[bp-0xa]
        imul word ptr mn69F8
        add ax,mn005A
        jmp short $+5
        nop
L9B:
        xor ax,ax
L9D:
    }
}
