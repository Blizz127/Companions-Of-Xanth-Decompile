extern int __near mn4DB2;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_97530(int a)
{
    _asm {
        sub sp,0x4
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov word ptr mn4DB2,0x1
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_1
        add sp,0x4
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov word ptr mn4DB2,0x0
        mov ax,dx
        or ax,[bp-0x4]
        jz short $+37
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        cmp [bp-0x4],ax
        jnz short $+7
        cmp [bp-0x2],dx
        jz short $+21
L48:
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push dx
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_2
L5B:
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
    }
}
