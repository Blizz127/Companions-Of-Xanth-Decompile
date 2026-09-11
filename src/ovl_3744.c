extern char __near mb036E;
extern int __near mn5D88;
extern int __near mn5D86;
extern int __near mn5D8A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_3744(void)
{
    _asm {
        mov ax,0xd
        push ax
        call far ptr helper_0
        add sp,0x2
        call far ptr helper_1
        mov ax,0x632a
        push ax
        call far ptr helper_2
        add sp,0x2
        call far ptr helper_3
        mov ax,0x1
        push ax
        mov cx,0x7f
        push cx
        cmp mb036E,al
        sbb cx,cx
        and cx,0xfe08
        add cx,0x302
        push cx
        call far ptr helper_4
        add sp,0x6
        call far ptr helper_5
        mov ax,0x1
        push ax
        call far ptr helper_6
        add sp,0x2
        sub ax,ax
        mov mn5D88,ax
        mov mn5D86,ax
        mov word ptr mn5D8A,0xa0
        retf
    }
}
