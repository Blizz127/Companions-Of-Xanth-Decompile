extern int __near mn63E0;
extern int __near mn63E2;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_97419(int a)
{
    _asm {
        sub sp,0x6
        call far ptr helper_0
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x6
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        or dx,ax
        jz short $+16
        les bx, [bp-0x4]
        mov word ptr es:[bx+0x4],0xffff
        mov byte ptr es:[bx+0xa],0x10
L31:
        call far ptr helper_2
        mov [bp-0x6],ax
        mov ax,mn63E0
        cmp [bp-0x6],ax
        jnc short $+17
        mov ax,[bp-0x6]
        mov mn63E0,ax
        cmp ax,mn63E2
        jnc short $+5
        mov mn63E2,ax
L50:
        mov ax,[bp-0x2]
        or ax,[bp-0x4]
        jz short $+15
        les bx, [bp-0x4]
        mov ax,es:[bx]
        mov dx,es:[bx+0x2]
        jmp short $+6
        nop
L65:
        xor ax,ax
        cwd
L68:
    }
}
