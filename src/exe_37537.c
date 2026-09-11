extern int __near mn0056;
extern int __near mn69F6;
extern int __near mn0058;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_37537(int a)
{
    _asm {
        mov ax,mn0056
        cmp [bp+0x6],ax
        jz short $+75
        mov word ptr mn69F6,0x0
        mov ax,0x34
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_0
        mov sp,bp
        call far ptr helper_1
        cmp word ptr [bp+0x6],0x1
        jnz short $+9
        call far ptr helper_2
        jmp short $+8
L2F:
        mov word ptr mn0058,0x1
L35:
        mov ax,[bp+0x6]
        mov mn0056,ax
        mov ax,0x20
        push ax
        call far ptr helper_3
        mov sp,bp
        mov word ptr mn0058,0x0
        call far ptr helper_4
L51:
    }
}
