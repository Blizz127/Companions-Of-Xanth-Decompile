extern int __near mn69F8;
extern int __near mn6D48;
extern int __near mn6DDA;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_235659(int a)
{
    _asm {
        sub sp,0x104
        lea ax,[bp+0xa]
        push ss
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        lea ax,[bp-0x100]
        push ss
        push ax
        call far ptr helper_1
        add sp,0xc
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x2
        xor ax,ax
        push ax
        call far ptr helper_3
        add sp,0x2
        mov ax,0xc7
        push ax
        mov ax,0x109
        push ax
        mov ax,0x63
        sub ax,mn69F8
        add ax,ax
        sub ax,mn6D48
        push ax
        xor ax,ax
        push ax
        call far ptr helper_4
        add sp,0x8
        push word ptr mn6D48
        push word ptr mn6DDA
        mov ax,0x1
        push ax
        call far ptr helper_5
        add sp,0x6
        lea ax,[bp-0x100]
        push ss
        push ax
        mov ax,0x3342
        push ds
        push ax
        call far ptr helper_6
        add sp,0x8
        mov ax,0xffff
        push ax
        call far ptr helper_3
    }
}
