extern int __near mn0256;
extern int __near mn5A52;
extern char __near mb6E5C;
extern int __near mn5A54;
extern int __near mn084C;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_60218(int a)
{
    _asm {
        sub sp,0x12
        mov word ptr [bp-0xa],0x0
        push word ptr mn0256
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x4],ax
        push word ptr mn0256
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x6],ax
        or ax,ax
        jnz short $+5
        jmp L141
L2D:
        dec word ptr [bp-0x6]
        cmp word ptr [bp-0x4],0x0
        jnz short $+5
        jmp L141
L39:
        mov ax,[bp-0x6]
        add ax,ax
        add ax,ax
        add ax,0x10fa
        mov [bp-0x12],ax
L46:
        mov al,[bp+0x6]
        mov es, mn5A52
        mov bx,[bp-0x12]
        cmp es:[bx],al
        jz short $+18
        add word ptr [bp-0x12],0x4
        inc word ptr [bp-0x6]
        dec word ptr [bp-0x4]
        jnz short $-25
        jmp L141
        nop
L65:
        mov al,[bp+0x6]
        mov mb6E5C,al
        mov bx,[bp-0x6]
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x10fc]
        mov [bp-0x8],ax
        mov al,es:[bx+0x10fb]
        sub ah,ah
        dec ax
        jz short $+33
        dec ax
        jz short $+38
        dec ax
        dec ax
        jz short $+128
L8B:
        cmp word ptr [bp-0xa],0x0
        jnz short $+5
        jmp L141
L94:
        push word ptr [bp-0xa]
        call far ptr helper_2
        add sp,0x2
        jmp short $+101
        nop
        nop
LA3:
        mov ax,[bp-0x8]
LA6:
        mov [bp-0xa],ax
        jmp short $-30
LAB:
        mov ax,0xe
        push ax
        mov es, mn5A54
        mov bx,[bp-0x8]
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x850]
        mov [bp-0x10],ax
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+20
        mov es, mn5A54
        mov bx,[bp-0x8]
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x84e]
        jmp short $-57
LE1:
        mov ax,0x7b2
        push ds
        push ax
        push word ptr [bp-0x10]
        mov ax,0x52
        push ax
        call far ptr helper_4
        add sp,0x8
        push dx
        push ax
        mov ax,0x7b6
        push ds
        push ax
        call far ptr helper_5
        add sp,0x8
L104:
        mov ax,0x1
        jmp short $+73
L109:
        mov ax,0xf
        push ax
        push word ptr [bp-0x8]
        call far ptr helper_6
        add sp,0x4
        mov [bp-0x10],ax
        or ax,ax
        jnl short $+5
        jmp L8B
L122:
        mov ax,mn084C
        cmp [bp-0x10],ax
        jng short $+5
        jmp L8B
L12D:
        cmp word ptr [bp-0x10],0x0
        jz short $-45
        mov ax,mn0256
        cmp [bp-0x10],ax
        jz short $-53
        mov ax,[bp-0x10]
        jmp LA6
L141:
        mov ax,0x0
        mov cx,0x235e
        push cx
        push ax
        call far ptr helper_5
        xor ax,ax
L150:
    }
}
