extern int __near mn5806;
extern int __near mn5808;
extern int __near mn580A;
extern int __near mn580C;
void far helper_0(void);
void far helper_1(void);
int far exe_17018(int a)
{
    _asm {
        sub sp,0xe
        mov word ptr mn5806,0x0
        lea ax,[bp-0xa]
        push ss
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x3e8
        cwd
        push dx
        push ax
        mov ax,[bp-0xa]
        mov dx,[bp-0x8]
        sub ax,mn5808
        sbb dx,mn580A
        push dx
        push ax
        call far ptr helper_1
        mov cx,ax
        mov ax,[bp-0x6]
        sub ax,mn580C
        mov bx,dx
        cwd
        add ax,cx
        adc dx,bx
        mov [bp-0xe],ax
        mov [bp-0xc],dx
    }
}
