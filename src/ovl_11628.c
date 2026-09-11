extern int __near mn69F8;
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
int far ovl_11628(int a)
{
    _asm {
        call far ptr helper_0
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        cmp word ptr [bp+0xa],0x1
        sbb cx,cx
        and cx,0x1
        add cx,0x21
        push cx
        call far ptr helper_2
        add sp,0x4
        call far ptr helper_3
        xor ax,ax
        push ax
        call far ptr helper_4
        add sp,0x2
        mov ax,0xffff
        push ax
        mov cx,0xf
        push cx
        call far ptr helper_5
        add sp,0x4
        mov ax,[bp+0x8]
        inc ax
        push ax
        mov cx,[bp+0x6]
        add cx,0x14
        push cx
        mov si,ax
        mov di,cx
        call far ptr helper_6
        add sp,0x4
        mov ax,[bp+0x8]
        add ax,mn69F8
        inc ax
        push ax
        mov ax,0xd7
        push ax
        push si
        push di
        call far ptr helper_7
        add sp,0x8
        cmp word ptr [bp+0xa],0x0
        jz short $+7
        mov ax,0x17d5
        jmp short $+5
lbl87:
        mov ax,0x17d8
lbl8A:
        push ds
        push ax
        call far ptr helper_8
        add sp,0x4
        mov ax,0xffff
        push ax
        call far ptr helper_4
        add sp,0x2
        call far ptr helper_9
    }
}
