extern int __near mn02A4;
extern char __near mb278A;
extern char __near mb278B;
int g;
char g0;
char g1;
void far helper_mkfp(void);
int far if15_131563(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0xf
        jnz short $+54
        cmp word ptr mn02A4,0x1
        jna short $+9
        mov ax,0x2796
        mov dx,ds
        jmp short $+5
L17:
        xor ax,ax
        cwd
L1A:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0xd
        mov dx,0xf00f
        push dx
        push ax
        call far ptr helper_mkfp
        add sp,0x8
        xor al,al
        mov mb278A,al
        mov mb278B,al
        jmp short $+15
        nop
L3D:
        cmp word ptr mn02A4,0x1
        jna short $+7
        mov ax,0x9c
        jmp short $+5
L49:
        mov ax,0x98
L4C:
    }
}
