void far helper_0(void);
void far helper_1(void);
int far exe_114295(int a)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        mov sp,bp
        mov cl,0x3
        mov ax,[bp+0xc]
        shl ax,cl
        sub ax,0x4
        mov [bp+0xc],ax
        push ax
        mov ax,[bp+0xa]
        shl ax,cl
        sub ax,0x4
        mov [bp+0xa],ax
        push ax
        mov ax,[bp+0x8]
        shl ax,cl
        sub ax,0x4
        mov [bp+0x8],ax
        push ax
        mov ax,[bp+0x6]
        shl ax,cl
        sub ax,0x4
        mov [bp+0x6],ax
        push ax
        call far ptr helper_1
    }
}
