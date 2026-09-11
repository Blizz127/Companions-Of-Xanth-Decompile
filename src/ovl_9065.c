extern int __near mn4232;
extern int __near mn6A1C;
extern int __near mn6A1A;
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
int far ovl_9065(int a)
{
    _asm {
        mov ax,0x1772
        push ds
        push ax
        call far ptr helper_0
        mov sp,bp
        call far ptr helper_1
        mov ax,0x26a
        push ds
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x28
        mov cx,0x2ec4
        push cx
        push ax
        mov ax,0x6
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x48
        mov cx,0x2ec4
        push cx
        push ax
        mov ax,0x4
        push ax
        call far ptr helper_3
        mov sp,bp
        mov ax,0x48
        mov cx,0x2ec4
        push cx
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_3
        mov sp,bp
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_4
        mov sp,bp
        call far ptr helper_5
        call far ptr helper_6
        call far ptr helper_7
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_8
        mov sp,bp
        call far ptr helper_9
        mov ax,mn4232
        mov mn6A1C,ax
        mov word ptr mn6A1A,0x1
        xor ax,ax
        push ax
        call far ptr helper_10
        mov sp,bp
        mov ax,0x1a
        push ax
        call far ptr helper_11
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov ax,0x0
        mov cx,0x2252
        push cx
        push ax
        call far ptr helper_12
        mov sp,bp
        call far ptr helper_13
        call far ptr helper_14
        call far ptr helper_15
        call far ptr helper_16
        mov ax,0x1
        push ax
        call far ptr helper_17
    }
}
