void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far exe_106359(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x14
        imul word ptr [bp+0x8]
        sub dx,dx
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,ax
        jnz short $+5
        jmp LA4
L22:
        xor ax,ax
        push ax
        call far ptr helper_1
        add sp,0x2
        push word ptr [bp+0x8]
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_2
        add sp,0x6
        mov ax,0x1
        push ax
        push word ptr [bp+0x6]
        push word ptr [bp+0x8]
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_3
        add sp,0xa
        mov [bp+0x8],ax
        cmp byte ptr [bp+0xa],0x0
        jnz short $+16
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_4
        jmp short $+14
L6D:
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_5
L79:
        add sp,0x6
        push word ptr [bp+0x8]
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_6
        add sp,0x6
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_7
        add sp,0x4
        mov ax,0x1
        push ax
        call far ptr helper_1
LA4:
    }
}
