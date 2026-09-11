extern int __near mn69FC;
extern int __near mn0266;
void far helper_0(void);
int far exe_56581(int a)
{
    _asm {
        sub sp,0x6
        mov ax,mn69FC
        add ax,ax
        add ax,ax
        add ax,0x0
        mov [bp-0x4],ax
        mov word ptr [bp-0x2],0x2263
        mov ax,mn0266
        cmp [bp+0x6],ax
        jz short $+48
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+11
        les bx, [bp-0x4]
        mov es:[bx],ax
        jmp short $+11
        nop
L35:
        les bx, [bp-0x4]
        mov word ptr es:[bx],0x100
L3D:
        mov ax,[bp+0x6]
        les bx, [bp-0x4]
        mov es:[bx+0x2],ax
        inc word ptr mn69FC
L4B:
        xor ax,ax
    }
}
