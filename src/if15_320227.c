extern char __near mb3A8A;
char g;
void far helper(void);
void far helper_mkfp(void);
void far helper2(void);
void far helper3(void);
void far helper4(void);
int far if15_320227(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+7
L06:
        mov ax,0x1d5
        jmp short $+88
L0B:
        mov ax,0x1ce
        push ax
        mov ax,0x1c3
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jz short $+31
        mov ax,0x22
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        mov ax,0x3aa5
        push ds
        push ax
        call far ptr helper2
        mov sp,bp
        jmp short $+-51
L3B:
        mov ax,0x23
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper3
        mov sp,bp
        mov byte ptr mb3A8A,0x1
        call far ptr helper4
        xor ax,ax
L61:
    }
}
