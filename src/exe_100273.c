extern int __near mn6436;
extern int __near mn6434;
void far helper_0(void);
int far exe_100273(int a)
{
    _asm {
        sub sp,0x2
        mov word ptr [bp-0x2],0x0
L08:
        mov bl,[bp+0x6]
        and bx,0x7
        mov al,[bx+0x4f3a]
        cbw
        mov [bp+0x6],ax
        mov ax,0x5
        mov bx,[bp+0x6]
        int 0x33
        add [bp-0x2],bx
        call far ptr helper_0
        cmp dx,mn6436
        jg short $+16
        jl short $+8
        cmp ax,mn6434
        jnc short $+8
L34:
        cmp word ptr [bp-0x2],0x0
        jz short $-48
L3A:
        mov ax,[bp-0x2]
    }
}
