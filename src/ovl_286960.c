extern int __near mn0256;
extern int __near mn5B2A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
int far ovl_286960(int a)
{
    _asm {
        sub sp,0x8
        mov word ptr [bp-0x4],0x52
L08:
        mov ax,mn0256
        mov es, mn5B2A
        mov bx,[bp-0x4]
        sub bx,0x2
        cmp es:[bx],ax
        jz short $+5
        jmp L10F
L1D:
        mov ax,0xbb8
        push ax
        call far ptr helper_0
        add sp,0x2
        mov es, mn5B2A
        mov bx,[bp-0x4]
        sub bx,0xa
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        push word ptr mn0256
        mov bx,[bp-0x4]
        mov es, mn5B2A
        mov [bp-0x8],bx
        mov word ptr [bp-0x6],es
        push word ptr es:[bx]
        call far ptr helper_2
        add sp,0x6
        call far ptr helper_3
        les bx, [bp-0x8]
        cmp word ptr es:[bx],0x179
        jnz short $+20
        call far ptr helper_4
        mov ax,0x377b
        push ds
        push ax
        call far ptr helper_5
        add sp,0x4
L82:
        mov ax,0x1388
        push ax
        call far ptr helper_0
        add sp,0x2
        mov es, mn5B2A
        mov bx,[bp-0x4]
        push word ptr es:[bx+0x4]
        push word ptr es:[bx+0x2]
        call far ptr helper_6
        add sp,0x4
        les bx, [bp-0x8]
        cmp word ptr es:[bx],0x17d
        jnz short $+18
        mov ax,0x12
        mov dx,0xf02c
        push dx
        push ax
        call far ptr helper_7
        add sp,0x4
LBF:
        mov es, mn5B2A
        mov bx,[bp-0x4]
        sub bx,0x6
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        les bx, [bp-0x8]
        push word ptr es:[bx]
        mov ax,0x12
        push ax
        call far ptr helper_8
        add sp,0x4
        push dx
        push ax
        mov ax,0x3782
        push ds
        push ax
        call far ptr helper_7
        add sp,0xc
        mov ax,0xbb8
        push ax
        call far ptr helper_0
        add sp,0x2
        xor ax,ax
        push ax
        push ax
        les bx, [bp-0x8]
        push word ptr es:[bx]
        call far ptr helper_2
        add sp,0x6
L10F:
        add word ptr [bp-0x4],0x10
        cmp word ptr [bp-0x4],0x82
        jnc short $+5
        jmp L08
L11D:
        call far ptr helper_9
        mov ax,0x1
    }
}
