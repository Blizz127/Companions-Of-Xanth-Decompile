void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_106631(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x14
        imul word ptr [bp+0xa]
        add ax,[bp+0x6]
        mov dx,[bp+0x8]
        add ax,0xb
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        jmp short $+65
        nop
L1B:
        call far ptr helper_0
        mov cx,ax
        mov al,0x32
        les bx, [bp-0x4]
        mul byte ptr es:[bx]
        mov bx,ax
        inc bx
        mov ax,cx
        cwd
        idiv bx
        mov al,0x32
        mov bx,[bp-0x4]
        mul byte ptr es:[bx-0x1]
        add dx,ax
        push dx
        call far ptr helper_1
        add sp,0x2
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        sub ax,0xb
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
L59:
        sub word ptr [bp-0x4],0x14
        dec word ptr [bp+0xa]
        jns short $-69
    }
}
