extern int __near mn0068;
extern int __near mn006A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_36416(int a)
{
    _asm {
        mov ax,[bp+0x6]
        cmp mn0068,ax
        jnz short $+5
        jmp LA9
L0C:
        mov ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        call far ptr helper_1
        cmp word ptr mn0068,0x0
        jz short $+59
        cmp word ptr mn006A,0x0
        jng short $+52
        mov ax,0xffff
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_2
        mov sp,bp
        push word ptr mn006A
        mov ax,0x2
        push ax
        call far ptr helper_3
        mov sp,bp
        push word ptr mn0068
        call far ptr helper_4
        mov sp,bp
        push dx
        push ax
        call far ptr helper_5
        mov sp,bp
L5C:
        cmp word ptr [bp+0x6],0x0
        jz short $+56
        cmp word ptr [bp+0x8],0x0
        jng short $+50
        mov ax,0xffff
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_2
        mov sp,bp
        push word ptr [bp+0x8]
        mov ax,0x2
        push ax
        call far ptr helper_3
        mov sp,bp
        push word ptr [bp+0x6]
        call far ptr helper_4
        mov sp,bp
        push dx
        push ax
        call far ptr helper_5
        mov sp,bp
L98:
        call far ptr helper_6
        mov ax,[bp+0x6]
        mov mn0068,ax
        mov ax,[bp+0x8]
        mov mn006A,ax
LA9:
    }
}
