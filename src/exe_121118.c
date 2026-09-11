extern int __near mn51E2;
extern int __near mn51DE;
extern int __near mn69F8;
extern int __near mn6D24;
extern int __near mn51E4;
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
void far helper_9(void);
void far helper_10(void);
void far helper_11(void);
void far helper_12(void);
void far helper_13(void);
void far helper_14(void);
void far helper_15(void);
void far helper_16(void);
int far exe_121118(int a)
{
    _asm {
        sub sp,0x218
        call far ptr helper_0
        cmp word ptr mn51E2,0x1
        jnz short $+7
        call far ptr helper_1
L15:
        lea ax,[bp+0xe]
        push ss
        push ax
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        lea ax,[bp-0x204]
        push ss
        push ax
        call far ptr helper_2
        add sp,0xc
        cmp word ptr mn51DE,0x8
        jnz short $+14
        call far ptr helper_3
        mov ax,0xffff
        jmp L257
        nop
L41:
        mov ax,0x1
        push ax
        call far ptr helper_4
        add sp,0x2
        call far ptr helper_5
        or ax,ax
        jz short $+31
        mov ax,0xffff
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_6
        add sp,0x4
        xor ax,ax
        push ax
        call far ptr helper_7
        add sp,0x2
        jmp short $+17
L73:
        mov ax,0xffff
        push ax
        xor ax,ax
        push ax
        call far ptr helper_6
        add sp,0x4
L82:
        xor ax,ax
        mov [bp-0x206],ax
        mov [bp-0x208],ax
        mov [bp-0x20a],ax
        lea ax,[bp-0x204]
        mov [bp-0x4],ax
        mov word ptr [bp-0x2],ss
        mov bx,ax
        cmp byte ptr [bx],0x0
        jz short $+73
LA1:
        mov es, [bp-0x2]
        cmp byte ptr es:[bx],0xa
        jnz short $+17
        mov word ptr [bp-0x20a],0x0
        mov ax,mn69F8
        add [bp-0x208],ax
        jmp short $+37
LB9:
        mov al,es:[bx]
        cbw
        push ax
        call far ptr helper_8
        add sp,0x2
        add [bp-0x20a],ax
        mov ax,[bp-0x206]
        cmp [bp-0x20a],ax
        jng short $+10
        mov ax,[bp-0x20a]
        mov [bp-0x206],ax
LDC:
        inc word ptr [bp-0x4]
        les bx, [bp-0x4]
        cmp byte ptr es:[bx],0x0
        jnz short $-69
LE8:
        mov ax,mn6D24
        add [bp-0x206],ax
        mov ax,mn69F8
        add ax,ax
        inc ax
        add [bp-0x208],ax
        call far ptr helper_5
        or ax,ax
        jnz short $+7
        sub word ptr [bp-0x208],0x4
L107:
        cmp word ptr [bp+0x6],0x0
        jl short $+12
        mov ax,[bp+0x6]
        imul word ptr mn6D24
        jmp short $+15
        nop
L117:
        mov ax,0x13f
        sub ax,[bp-0x206]
        cwd
        sub ax,dx
        sar ax,1
L123:
        mov [bp-0x20c],ax
        cmp word ptr [bp+0x8],0x0
        jl short $+12
        mov ax,[bp+0x8]
        imul word ptr mn69F8
        jmp short $+16
        nop
L137:
        mov ax,0xc7
        sub ax,[bp-0x208]
        mov cx,0x3
        cwd
        idiv cx
L144:
        mov [bp-0x20e],ax
        mov ax,[bp-0x20c]
        add ax,[bp-0x206]
        mov [bp-0x210],ax
        mov ax,[bp-0x20e]
        add ax,[bp-0x208]
        mov [bp-0x212],ax
        cmp word ptr mn51E2,0x0
        jnz short $+18
        xor ax,ax
        push ax
        call far ptr helper_9
        add sp,0x2
        mov mn51E4,ax
        jmp short $+13
L177:
        xor ax,ax
        push ax
        call far ptr helper_9
        add sp,0x2
L182:
        xor ax,ax
        push ax
        push ax
        call far ptr helper_10
        add sp,0x4
        push word ptr [bp-0x212]
        push word ptr [bp-0x210]
        push word ptr [bp-0x20e]
        push word ptr [bp-0x20c]
        mov ax,0x14
        imul word ptr mn51E2
        add ax,0x6982
        push ds
        push ax
        call far ptr helper_11
        add sp,0xc
        call far ptr helper_12
        push word ptr [bp-0x212]
        push word ptr [bp-0x210]
        push word ptr [bp-0x20e]
        push word ptr [bp-0x20c]
        call far ptr helper_13
        add sp,0x8
        mov [bp-0x214],ax
        push word ptr [bp-0x212]
        push word ptr [bp-0x210]
        push word ptr [bp-0x20e]
        push word ptr [bp-0x20c]
        call far ptr helper_14
        add sp,0x8
        call far ptr helper_5
        or ax,ax
        jz short $+30
        mov ax,0x14
        push ax
        push word ptr [bp-0x212]
        push word ptr [bp-0x210]
        push word ptr [bp-0x20e]
        push word ptr [bp-0x20c]
        call far ptr helper_15
        add sp,0xa
L210:
        mov ax,mn51E0
        mov [bp-0x218],ax
        mov ax,[bp-0x214]
        mov mn51E0,ax
        lea cx,[bp-0x204]
        push ss
        push cx
        call far ptr helper_16
        add sp,0x4
        mov ax,[bp-0x218]
        mov mn51E0,ax
        mov ax,[bp-0x214]
        mov bx,mn51E2
        add bx,bx
        mov [bx+0x6980],ax
        inc word ptr mn51E2
        call far ptr helper_3
        mov ax,0xffff
        push ax
        call far ptr helper_7
        mov ax,[bp-0x214]
L257:
    }
}
