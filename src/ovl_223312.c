extern int __near mn5E0C;
extern int __near mn6D48;
extern int __near mn6DDA;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_223312(int a)
{
    _asm {
        sub sp,0x10
        mov ax,0xa
        push ax
        lea ax,[bp-0x10]
        push ss
        push ax
        push word ptr mn5E0C
        call far ptr helper_0
        add sp,0x8
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0xd
        push ax
        call far ptr helper_3
        add sp,0x2
        mov ax,0x9
        sub ax,mn6D48
        push ax
        lea ax,[bp-0x10]
        push ss
        push ax
        call far ptr helper_4
        add sp,0x4
        cwd
        sub ax,dx
        sar ax,1
        sub ax,mn6DDA
        neg ax
        add ax,0x16
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_5
        add sp,0x6
        lea ax,[bp-0x10]
        push ss
        push ax
        call far ptr helper_6
    }
}
