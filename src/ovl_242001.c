extern int __near mn4232;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_242001(int a)
{
    _asm {
        sub sp,0x8
        mov word ptr [bp-0x2],0x0
        cmp word ptr [bp+0xa],0x0
        jng short $+109
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x8],ax
        mov [bp-0x6],dx
L1A:
        sub ax,ax
        push ax
        push ax
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        call far ptr helper_0
        add sp,0x8
        cmp word ptr mn4232,0x0
        jnz short $+20
        les bx, [bp-0x8]
        push word ptr es:[bx+0x6]
        call far ptr helper_1
        add sp,0x2
        jmp short $+17
        nop
L45:
        call far ptr helper_2
        or ax,ax
        jz short $+10
        call far ptr helper_3
L53:
        mov [bp-0x4],ax
L56:
        call far ptr helper_4
        cmp word ptr [bp-0x4],0x1b
        jz short $+20
        add word ptr [bp-0x8],0x10
        mov ax,[bp+0xa]
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-84
        jmp short $+9
        nop
L73:
        mov ax,0x1
        jmp short $+5
        nop
L79:
        xor ax,ax
L7B:
    }
}
