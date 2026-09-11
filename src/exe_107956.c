extern int __near mn4F68;
void far helper_0(void);
void far helper_1(void);
int far exe_107956(int a)
{
    _asm {
        sub sp,0x6
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn4F68,0x0
        jng short $+106
        mov word ptr [bp-0x4],0x0
        mov word ptr [bp-0x6],0x675a
L19:
        mov bx,[bp-0x6]
        push word ptr [bx]
        mov bx,[bp-0x4]
        les bx, [bx+0x678a]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        call far ptr helper_0
        add sp,0x6
        mov bx,[bp-0x4]
        push word ptr [bx+0x678c]
        push word ptr [bx+0x678a]
        call far ptr helper_1
        add sp,0x4
        mov bx,[bp-0x4]
        sub ax,ax
        mov [bx+0x678c],ax
        mov [bx+0x678a],ax
        mov bx,[bp-0x6]
        add word ptr [bp-0x6],0x2
        mov [bx],ax
        mov bx,[bp-0x4]
        mov [bx+0x67a0],ax
        mov [bx+0x679e],ax
        add word ptr [bp-0x4],0x4
        mov ax,mn4F68
        inc word ptr [bp-0x2]
        cmp [bp-0x2],ax
        jl short $-92
L77:
        mov word ptr mn4F68,0x0
    }
}
