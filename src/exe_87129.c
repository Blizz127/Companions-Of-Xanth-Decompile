extern char __near mb6D21;
extern char __near mb6D22;
extern char __near mb6D23;
void far helper_0(void);
int far exe_87129(int a)
{
    _asm {
        sub sp,0x2
        mov word ptr [bp-0x2],0x0
L08:
        mov cx,0x3f
        mov ax,[bp-0x2]
        mov dx,0x3
        mov bx,dx
        cwd
        idiv bx
        imul cx
        mov cx,0xf
        cwd
        idiv cx
        mov bx,[bp-0x2]
        mov [bx+0x6a24],al
        inc word ptr [bp-0x2]
        cmp word ptr [bp-0x2],0x30
        jl short $-36
        mov al,0x3f
        mov mb6D21,al
        mov mb6D22,al
        mov mb6D23,al
        mov ax,0x6a24
        push ds
        push ax
        call far ptr helper_0
    }
}
