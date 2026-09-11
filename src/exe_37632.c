extern int __near mn0052;
extern int __near mn69FC;
extern int __near mn0064;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_37632(int a)
{
    _asm {
        sub sp,0x4
        call far ptr helper_0
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov ax,0x1
        push ax
        mov cx,0x3
        push cx
        call far ptr helper_1
        add sp,0x4
        mov ax,0xc3
        push ax
        mov ax,0x52
        push ax
        mov ax,0x98
        push ax
        mov ax,0x33
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_2
        add sp,0xc
        mov ax,0x2
        push ax
        xor ax,ax
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        push word ptr mn0052
        mov ax,0x3
        push ax
        call far ptr helper_3
        add sp,0xc
        call far ptr helper_4
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov ax,0x1
        push ax
        mov ax,0x4
        push ax
        call far ptr helper_1
        add sp,0x4
        cmp word ptr mn69FC,0xe
        ja short $+8
        mov word ptr mn0064,0x0
lbl81:
        mov ax,0xc3
        push ax
        mov ax,0x11f
        push ax
        mov ax,0x98
        push ax
        mov cx,0x58
        push cx
        mov cx,mn0064
        add cx,cx
        add cx,cx
        add cx,[bp-0x4]
        mov dx,[bp-0x2]
        push dx
        push cx
        call far ptr helper_2
        add sp,0xc
        mov ax,0xe
        push ax
        push word ptr mn0064
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        push word ptr mn0052
        mov ax,0x4
        push ax
        call far ptr helper_3
        add sp,0xc
        mov ax,0x98
        push ax
        mov ax,0x125
        push ax
        call far ptr helper_5
        add sp,0x4
        xor ax,ax
        push ax
        cmp word ptr mn69FC,0xe
        jna short $+8
        mov ax,0x103
        jmp short $+6
        nop
lblE7:
        mov ax,0x104
lblEA:
        push ax
        call far ptr helper_6
    }
}
