extern int __near mn62DA;
extern int __near mn62D8;
void far helper_0(void);
void far helper_1(void);
int far exe_83359(int a)
{
    _asm {
        sub sp,0xe
        mov ax,[bp+0x6]
        sub ax,0x4
        jl short $+7
        jo short $+5
        dec ax
        jng short $+33
L10:
        mov bx,[bp+0x6]
        add bx,bx
        add bx,bx
        push word ptr [bx+0x42ac]
        push word ptr [bx+0x42aa]
        push word ptr [bp+0x8]
        push word ptr mn62DA
        push word ptr mn62D8
        mov ax,0x42d4
        jmp short $+31
L2F:
        mov bx,[bp+0x6]
        add bx,bx
        add bx,bx
        push word ptr [bx+0x42ac]
        push word ptr [bx+0x42aa]
        push word ptr [bp+0x8]
        push word ptr mn62DA
        push word ptr mn62D8
        mov ax,0x42ca
L4C:
        push ds
        push ax
        lea ax,[bp-0xe]
        push ss
        push ax
        call far ptr helper_0
        add sp,0x12
        lea ax,[bp-0xe]
        push ss
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_1
    }
}
