extern int __near mn0256;
extern int __near mn6A0E;
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
int far exe_56920(void)
{
    _asm {
        call far ptr helper_0
        mov ax,0x128
        push ax
        mov ax,0x56
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xe
        push ax
        mov ax,0x31
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x2c
        push ax
        mov ax,0x31
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x7
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0xc
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,mn0256
        mov mn6A0E,ax
        mov ax,0x10
        push ax
        call far ptr helper_5
        add sp,0x2
        push word ptr mn0256
        call far ptr helper_6
        add sp,0x2
        mov ax,0x1
        push ax
        call far ptr helper_7
        add sp,0x2
        mov ax,0x19
        push ax
        push word ptr mn0256
        call far ptr helper_8
        add sp,0x4
        mov ax,0x9
        push ax
        push word ptr mn0256
        call far ptr helper_8
        add sp,0x4
        mov ax,0xb
        push ax
        call far ptr helper_9
        add sp,0x2
        mov ax,0x6
        push ax
        push word ptr mn0256
        call far ptr helper_10
        add sp,0x4
        mov ax,0x5
        push ax
        push word ptr mn0256
        call far ptr helper_10
        add sp,0x4
        retf
    }
}
