extern int __near mn084C;
void far helper_0(void);
void far helper_1(void);
int far exe_57304(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0x0
        jng short $+48
        mov ax,mn084C
        cmp [bp+0x6],ax
        jg short $+40
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x2],dx
        or dx,ax
        jnz short $+16
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x2],dx
L31:
        mov dx,[bp-0x2]
        jmp short $+8
        nop
L37:
        mov ax,0x737
        mov dx,ds
L3C:
    }
}
