extern char __near mb4E9E;
extern int __near mn6428;
extern int __near mn642A;
void far helper_0(void);
int far exe_100086(int a)
{
    _asm {
        sub sp,0x6
        mov ax,0x3
        int 0x33
        shr cx,1
        mov [bp-0x4],cx
        mov [bp-0x6],dx
        mov [bp-0x2],bx
        test byte ptr mb4E9E,0x2
        jz short $+33
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+11
        mov ax,mn6428
        les bx, [bp+0x6]
        mov es:[bx],ax
L2B:
        mov ax,[bp+0xc]
        or ax,[bp+0xa]
        jz short $+56
        mov ax,mn642A
        jmp short $+45
        nop
L39:
        push word ptr [bp-0x6]
        push word ptr [bp-0x4]
        call far ptr helper_0
        add sp,0x4
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+11
        mov ax,[bp-0x4]
        les bx, [bp+0x6]
        mov es:[bx],ax
L58:
        mov ax,[bp+0xc]
        or ax,[bp+0xa]
        jz short $+11
        mov ax,[bp-0x6]
L63:
        les bx, [bp+0xa]
        mov es:[bx],ax
L69:
        mov ax,[bp-0x2]
    }
}
