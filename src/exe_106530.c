void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_106530(int a)
{
    _asm {
        sub sp,0x8
        cmp word ptr [bp+0xa],0x0
        jng short $+87
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x6],ax
        mov [bp-0x4],dx
        mov ax,[bp+0xa]
        mov [bp-0x8],ax
L1B:
        push word ptr [bp-0x4]
        push word ptr [bp-0x6]
        call far ptr helper_0
        add sp,0x4
        call far ptr helper_1
        mov cx,ax
        mov al,0x32
        les bx, [bp-0x6]
        mul byte ptr es:[bx+0xb]
        mov bx,ax
        inc bx
        mov ax,cx
        cwd
        idiv bx
        mov al,0x32
        mov bx,[bp-0x6]
        mul byte ptr es:[bx+0xa]
        add dx,ax
        push dx
        call far ptr helper_2
        add sp,0x2
        add word ptr [bp-0x6],0x14
        dec word ptr [bp-0x8]
        jnz short $-65
L5E:
    }
}
