extern int __near mn0050;
extern int __near mn0052;
extern int __near mn0054;
extern int __near mn5A1E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_37438(int a)
{
    _asm {
        sub sp,0x4
        xor ax,ax
        mov mn0050,ax
        mov mn0052,ax
        mov mn0054,ax
        mov bx,0x34
        mov es, mn5A1E
        mov [bp-0x4],bx
        mov word ptr [bp-0x2],es
        cmp es:[bx],al
        jz short $+40
        push ax
        push ax
        call far ptr helper_0
        add sp,0x4
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_1
        add sp,0x4
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_2
        add sp,0x4
L46:
        xor ax,ax
        push ax
        push ax
        call far ptr helper_3
        add sp,0x4
        call far ptr helper_4
        call far ptr helper_5
    }
}
