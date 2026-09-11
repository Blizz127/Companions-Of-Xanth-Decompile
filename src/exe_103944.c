extern int __near mn4F54;
extern int __near mn4F48;
extern int __near mn6E0C;
extern int __near mn4F52;
extern int __near mn4F46;
extern int __near mn6E0A;
extern char __near mb6E09;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_103944(int a)
{
    _asm {
        sub sp,0xa
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+6
L15:
        xor ax,ax
        jmp short $+102
L19:
        mov ax,mn4F54
        add ax,mn4F48
        mov cx,ax
        add ax,mn6E0C
        dec ax
        push ax
        mov ax,mn4F52
        add ax,mn4F46
        mov dx,ax
        add ax,mn6E0A
        dec ax
        push ax
        mov [bp-0x6],cx
        push cx
        mov [bp-0x4],dx
        push dx
        call far ptr helper_1
        add sp,0x8
        mov al,mb6E09
        and ax,0x40
        push ax
        push word ptr mn6E0A
        push word ptr [bp-0x6]
        push word ptr [bp-0x4]
        call far ptr helper_2
        add sp,0x8
        mov [bp-0x2],ax
        call far ptr helper_3
        cmp word ptr [bp-0x2],0x0
        jnz short $-87
        test byte ptr mb6E09,0x10
        jz short $+7
        call far ptr helper_4
L7A:
        mov ax,0x1
L7D:
    }
}
