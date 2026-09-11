extern int __near mn5A64;
extern char __near mb6A51;
extern char __near mb6A52;
extern char __near mb6A53;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_902(int a)
{
    _asm {
        sub sp,0x2
        mov ax,0xf
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0xd
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x0
        mov cx,0x311c
        push cx
        push ax
        mov ax,0x50
        push ax
        call far ptr helper_2
        add sp,0x6
        mov ax,0x30
        mov cx,0x311c
        push cx
        push ax
        mov ax,0x5f
        push ax
        call far ptr helper_2
        add sp,0x6
        mov word ptr [bp-0x2],0x0
L48:
        mov al,[bp-0x2]
        mov es, mn5A64
        mov es:mb6A51,al
        mov es:mb6A52,al
        mov es:mb6A53,al
        mov ax,0x6a24
        push es
        push ax
        call far ptr helper_3
        add sp,0x4
        inc word ptr [bp-0x2]
        cmp word ptr [bp-0x2],0x3f
        jng short $-39
        mov ax,0x2ee
        push ax
        call far ptr helper_4
        add sp,0x2
        mov word ptr [bp-0x2],0x3f
L82:
        mov al,[bp-0x2]
        mov es, mn5A64
        mov es:mb6A51,al
        mov es:mb6A52,al
        mov es:mb6A53,al
        mov ax,0x6a24
        push es
        push ax
        call far ptr helper_3
        add sp,0x4
        dec word ptr [bp-0x2]
        jns short $-35
        call far ptr helper_5
    }
}
