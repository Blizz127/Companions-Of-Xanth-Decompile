extern int __near mn42EA;
void far helper_0(void);
void far helper_1(void);
int far exe_87374(int a)
{
    _asm {
        sub sp,0xe
        mov byte ptr [bp-0xd],0x3
        mov byte ptr [bp-0xb],0x0
        lea ax,[bp-0xe]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_0
        add sp,0xa
        dec word ptr [bp+0x6]
        mov al,[bp-0x7]
        sub ah,ah
        dec word ptr [bp+0x8]
        cmp ax,[bp+0x8]
        jnz short $+10
        mov al,[bp-0x8]
        cmp ax,[bp+0x6]
        jz short $+65
L36:
        cmp word ptr mn42EA,0x0
        jz short $+7
        call far ptr helper_1
L42:
        mov byte ptr [bp-0xd],0x2
        mov byte ptr [bp-0xb],0x0
        mov al,[bp+0x8]
        mov [bp-0x7],al
        mov al,[bp+0x6]
        mov [bp-0x8],al
        lea ax,[bp-0xe]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_0
        add sp,0xa
        cmp word ptr mn42EA,0x0
        jz short $+7
        call far ptr helper_1
L75:
    }
}
