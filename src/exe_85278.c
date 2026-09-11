extern int __near mn6340;
extern int __near mn6344;
extern int __near mn634A;
extern int __near mn6348;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_85278(int a)
{
    _asm {
        sub sp,0x4
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp+0x6],ax
        mov [bp+0x8],dx
        les bx, mn6340
        cmp byte ptr es:[bx+0x3],0xff
        jz short $+5
        jmp LAC
L25:
        cmp word ptr mn6344,0x0
        jz short $+11
        mov ax,mn6344
        mov [bp-0x4],ax
        jmp short $+8
        nop
L35:
        mov word ptr [bp-0x4],0xf
L3A:
        xor ax,ax
        push ax
        push word ptr [bp-0x4]
        call far ptr helper_1
        add sp,0x4
        mov ax,mn634A
        cwd
        and dx,0x7
        add ax,dx
        mov cx,0x3
        sar ax,cl
        inc ax
        push ax
        mov ax,mn6348
        cwd
        and dx,0x7
        add ax,dx
        sar ax,cl
        inc ax
        push ax
        call far ptr helper_2
        add sp,0x4
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_3
        add sp,0x4
        mov ax,0x634a
        push ds
        push ax
        mov cx,0x6348
        push ds
        push cx
        call far ptr helper_4
        add sp,0x8
        mov cl,0x3
        mov ax,mn6348
        dec ax
        shl ax,cl
        mov mn6348,ax
        mov ax,mn634A
        dec ax
        shl ax,cl
        mov mn634A,ax
        jmp short $+49
LA3:
        push ax
        call far ptr helper_5
        add sp,0x2
LAC:
        les bx, [bp+0x6]
        inc word ptr [bp+0x6]
        mov al,es:[bx]
        sub ah,ah
        or ax,ax
        jnz short $-22
        les bx, mn6340
        cmp es:[bx+0x3],ah
        jnz short $+15
        push word ptr mn634A
        push word ptr mn6348
        call far ptr helper_6
LD2:
    }
}
