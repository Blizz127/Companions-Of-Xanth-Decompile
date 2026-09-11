extern int __near mn634C;
extern int __near mn634E;
extern int __near mn6350;
extern int __near mn6352;
extern int __near mn42EA;
extern int __near mn42E0;
extern int __near mn42E4;
extern int __near mn42E2;
extern int __near mn42E6;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_86559(int a)
{
    _asm {
        sub sp,0x6
        lea ax,[bp-0x4]
        push ss
        push ax
        call far ptr helper_0
        cmp byte ptr [bp-0x3],0x4
        jnz short $+8
        mov ax,0x3ba
        jmp short $+6
        nop
L19:
        mov ax,0x3da
L1C:
        mov mn634C,ax
        xor ax,ax
        push ax
        call far ptr helper_1
        or ax,ax
        jz short $+20
        mov ax,0x42f0
L2E:
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        xor ax,ax
        jmp short $+75
        nop
L3D:
        mov ax,0x1
        push ax
        call far ptr helper_3
        or ax,ax
        jz short $+7
        mov ax,0x430f
        jmp short $-31
L4F:
        mov ax,0xf
        mov mn634E,ax
        mov mn6350,ax
        xor ax,ax
        mov mn6352,ax
        mov mn42EA,ax
        call far ptr helper_4
        mov ax,0x1
        push ax
        call far ptr helper_5
        mov word ptr mn42E0,0x0
        sub ax,ax
        mov mn42E4,ax
        mov mn42E2,ax
        mov word ptr mn42E6,0xa000
        mov ax,0x1
L85:
    }
}
