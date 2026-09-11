extern int __near mn4FB8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_109844(int a)
{
    _asm {
        sub sp,0x16
        mov ax,[bp+0xe]
        sub ax,[bp+0xa]
        mov mn4FB8,ax
        mov ax,[bp+0xc]
        sub ax,[bp+0x8]
        inc ax
        push ax
        mov ax,0x515e
        push ds
        push ax
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        call far ptr helper_0
        add sp,0xa
        mov [bp-0x16],ax
        mov word ptr mn4FB8,0xb
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        push word ptr [bp+0x6]
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,[bp+0xa]
        add ax,0x2
        push ax
        mov ax,[bp+0x8]
        add ax,0x2
        push ax
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_3
        add sp,0x8
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_4
        mov ax,[bp-0x16]
    }
}
