extern int __near mn51E0;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far exe_115359(int a)
{
    _asm {
        sub sp,0x4
        mov bx,mn51E0
        add bx,bx
        add bx,bx
        mov ax,[bx+0x6960]
        mov dx,[bx+0x6962]
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        cmp word ptr [bp+0x6],0x0
        jnz short $+5
        jmp LD9
L22:
        mov ax,dx
        or ax,[bp-0x4]
        jz short $+5
        jmp L13A
L2C:
        call far ptr helper_0
        call far ptr helper_1
        mov ax,0x17
        push ax
        call far ptr helper_2
        add sp,0x2
        push word ptr mn51E0
        call far ptr helper_3
        add sp,0x2
        xor ax,ax
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x2e
        cwd
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        mov bx,mn51E0
        add bx,bx
        add bx,bx
        mov [bx+0x6960],ax
        mov [bx+0x6962],dx
        mov bx,mn51E0
        add bx,bx
        add bx,bx
        mov ax,[bx+0x6960]
        mov dx,[bx+0x6962]
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,ax
        jz short $+58
        les bx, [bp-0x4]
        sub ax,ax
        mov es:[bx+0x2],ax
        mov es:[bx],ax
        lea ax,[bx+0x4]
        push es
        push ax
        call far ptr helper_5
        add sp,0x4
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        add ax,0x18
        push dx
        push ax
        call far ptr helper_5
        add sp,0x4
        les bx, [bp-0x4]
        mov word ptr es:[bx+0x2c],0x0
        jmp short $+116
        nop
LC9:
        mov ax,0x51e6
        push ds
        push ax
        call far ptr helper_6
        add sp,0x4
        jmp short $+100
        nop
LD9:
        mov ax,dx
        or ax,[bp-0x4]
        jz short $+92
        les bx, [bp-0x4]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        call far ptr helper_7
        add sp,0x4
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        add ax,0x4
        push dx
        push ax
        call far ptr helper_8
        add sp,0x4
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        add ax,0x18
        push dx
        push ax
        call far ptr helper_8
        add sp,0x4
        les bx, [bp-0x4]
        mov word ptr es:[bx+0x2c],0x0
        push es
        push bx
        call far ptr helper_7
        mov bx,mn51E0
        add bx,bx
        add bx,bx
        sub ax,ax
        mov [bx+0x6962],ax
        mov [bx+0x6960],ax
L13A:
    }
}
