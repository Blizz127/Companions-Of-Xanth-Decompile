extern int __near mn6348;
extern int __near mn634A;
extern int __near mn6340;
void far helper_0(void);
int far exe_85217(int a)
{
    _asm {
        mov ax,[bp+0x6]
        mov mn6348,ax
        mov ax,[bp+0x8]
        mov mn634A,ax
        les bx, mn6340
        cmp byte ptr es:[bx+0x3],0x0
        jnz short $+33
        cwd
        and dx,0x7
        add ax,dx
        mov cx,0x3
        sar ax,cl
        inc ax
        push ax
        mov ax,[bp+0x6]
        cwd
        and dx,0x7
        add ax,dx
        sar ax,cl
        inc ax
        push ax
        call far ptr helper_0
L36:
    }
}
