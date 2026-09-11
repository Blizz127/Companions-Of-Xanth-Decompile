extern int __near mn51DE;
extern int __near mn51E0;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_114622(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0x0
        jz short $+7
        call far ptr helper_0
L0E:
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn51DE,0x0
        jng short $+71
        mov word ptr [bp-0x4],0x6860
L1F:
        mov ax,[bp-0x2]
        mov mn51E0,ax
        xor cx,cx
        push cx
        call far ptr helper_1
        mov bx,[bp-0x4]
        add sp,0x2
        mov word ptr [bx],0x0
        push word ptr [bp-0x2]
        call far ptr helper_2
        add sp,0x2
        xor ax,ax
        push ax
        push word ptr [bp-0x2]
        call far ptr helper_3
        add sp,0x4
        add word ptr [bp-0x4],0x2
        mov ax,mn51DE
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-62
L5F:
        mov word ptr mn51DE,0x0
        mov word ptr mn51E0,0xffff
    }
}
