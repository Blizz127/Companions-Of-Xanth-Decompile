extern int __near mn0256;
extern int __near mn5A42;
extern int __near mn4F4E;
void far helper_0(void);
void far helper_1(void);
int far exe_56005(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x13
        push ax
        push word ptr mn0256
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+109
        mov ax,0x1
        push ax
        push ax
        mov ax,0x54
        push ax
        call far ptr helper_1
        add sp,0x6
        or ax,ax
        jnz short $+88
        mov word ptr [bp-0x2],0x60
        mov es, mn5A42
L35:
        mov al,0x1f
        mov bx,[bp-0x2]
        imul byte ptr es:[bx+0x6a24]
        mov cx,ax
        mov al,0x11
        imul byte ptr es:[bx+0x6a26]
        add cx,ax
        mov al,0x34
        imul byte ptr es:[bx+0x6a25]
        add ax,cx
        add ax,0x32
        mov cx,0x64
        cwd
        idiv cx
        mov [bp-0x4],ax
        mov es:[bx+0x6a24],al
        mov al,[bp-0x4]
        mov es:[bx+0x6a25],al
        mov es:[bx+0x6a26],al
        add word ptr [bp-0x2],0x3
        cmp word ptr [bp-0x2],0x2fa
        jl short $-69
        mov word ptr mn4F4E,0x1
L82:
    }
}
