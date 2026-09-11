extern int __near mn02AA;
extern int __near mn5A3C;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_55711(void)
{
    _asm {
        mov ax,0xb
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0xfa0
        push ax
        call far ptr helper_1
        add sp,0x2
        inc word ptr mn02AA
        mov bx,mn02AA
        add bx,bx
        push word ptr [bx+0x404]
        mov ax,0x8b
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x20
        push ax
        call far ptr helper_3
        add sp,0x2
        mov es, mn5A3C
        mov bx,mn02AA
        add bx,bx
        add bx,bx
        push word ptr es:[bx+0x7ae]
        push word ptr es:[bx+0x7ac]
        mov ax,0x44
        mov dx,0xf000
        push dx
        push ax
        call far ptr helper_4
        add sp,0x8
        retf
    }
}
