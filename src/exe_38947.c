extern int __near mn0056;
extern int __near mn69F2;
extern int __near mn0256;
extern int __near mn69F4;
extern int __near mn5A1E;
extern int __near mn42E8;
extern int __near mn69F6;
extern int __near mn0070;
extern int __near mn002E;
extern int __near mn002C;
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
void far helper_17(void);
void far helper_18(void);
void far helper_19(void);
int far exe_38947(int a)
{
    _asm {
        sub sp,0x8
        cmp word ptr mn0056,0x1
        jnz short $+5
        jmp L1A2
L0D:
        call far ptr helper_0
        mov word ptr mn69F2,0x0
        push word ptr mn0256
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x4],ax
        inc ax
        jz short $+42
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x2
        call far ptr helper_3
        mov ax,0x1
        push ax
        call far ptr helper_4
        add sp,0x2
        push word ptr [bp-0x4]
        call far ptr helper_5
        add sp,0x2
L52:
        mov ax,mn69F4
        cmp [bp-0x4],ax
        jnz short $+43
        mov bx,0x20
        mov es, mn5A1E
        mov [bp-0x8],bx
        mov word ptr [bp-0x6],es
        cmp byte ptr es:[bx],0x0
        jz short $+24
        cmp word ptr mn42E8,0x0
        jnz short $+5
        jmp L125
L77:
        push ax
        call far ptr helper_6
        add sp,0x2
        jmp L125
L83:
        mov word ptr mn69F2,0x1
        mov ax,[bp-0x4]
        mov mn69F4,ax
        mov ax,0x20
        mov cx,0x2199
        mov [bp-0x8],ax
        mov [bp-0x6],cx
        push cx
        push ax
        call far ptr helper_7
        add sp,0x4
        cmp word ptr mn69F4,-1
        jnz short $+45
        xor ax,ax
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x1
        push ax
        call far ptr helper_9
        add sp,0x2
        xor ax,ax
        push ax
        call far ptr helper_8
        add sp,0x2
        mov word ptr mn69F6,0x1
        jmp short $+81
        nop
LD7:
        xor ax,ax
        push ax
        push word ptr mn69F4
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        call far ptr helper_10
        add sp,0x8
        push word ptr mn0070
        mov es, mn5A1E
        push word ptr es:mn002E
        push word ptr es:mn002C
        call far ptr helper_11
        add sp,0x6
        les bx, [bp-0x8]
        cmp byte ptr es:[bx],0x0
        jnz short $+18
        mov ax,0x48
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_12
        add sp,0x4
L11F:
        mov word ptr mn69F6,0x0
L125:
        mov ax,0x16
        push ax
        push word ptr mn0256
        call far ptr helper_13
        add sp,0x4
        or ax,ax
        jz short $+8
        mov word ptr mn69F6,0x0
L13F:
        call far ptr helper_14
        call far ptr helper_15
        cmp word ptr mn69F6,0x0
        jz short $+9
        call far ptr helper_16
        jmp short $+77
L157:
        mov word ptr mn69F6,0x1
        call far ptr helper_17
        cmp word ptr mn42E8,0x0
        jnz short $+7
        call far ptr helper_16
L16E:
        les bx, [bp-0x8]
        cmp byte ptr es:[bx],0x0
        jz short $+28
        mov ax,0x1
        push ax
        call far ptr helper_4
        add sp,0x2
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        call far ptr helper_18
        add sp,0x4
L191:
        cmp word ptr mn42E8,0x0
        jz short $+7
        call far ptr helper_16
L19D:
        call far ptr helper_19
L1A2:
    }
}
