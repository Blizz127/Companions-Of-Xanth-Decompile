extern int __near mn4F46;
extern int __near mn4F48;
int g0;
int g1;
void far helper(void);
void far exe_103774(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0x0
        jnl short $+10
        xor ax,ax
        mov mn4F46,ax
        jmp short $+30
        nop
L11:
        lea ax,[bp-0x4]
        push ss
        push ax
        lea cx,[bp-0x2]
        push ss
        push cx
        push word ptr [bp+0x6]
        call far ptr helper
        mov ax,[bp-0x2]
        mov mn4F46,ax
        mov ax,[bp-0x4]
L2C:
        mov mn4F48,ax
    }
}
