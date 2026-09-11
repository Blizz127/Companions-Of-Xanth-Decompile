extern int __near mn5B26;
extern int __near mn02D0;
void far helper_0(void);
void far helper_1(void);
int far ovl_258879(int a)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x2],0x0
        mov word ptr [bp-0x4],0x3498
L0D:
        mov es, mn5B26
        mov cl,0x4
        mov bx,mn02D0
        mov ax,bx
        add bx,bx
        add bx,bx
        add bx,ax
        add bx,[bp-0x2]
        shl bx,cl
        push word ptr es:[bx+0x5c2]
        mov bx,[bp-0x4]
        push word ptr [bx]
        call far ptr helper_0
        add sp,0x4
        mov ax,0x1
        push ax
        mov cx,0x143
        push cx
        mov bx,[bp-0x4]
        push word ptr [bx]
        call far ptr helper_1
        add sp,0x6
        inc word ptr [bp-0x2]
        add word ptr [bp-0x4],0x2
        cmp word ptr [bp-0x4],0x34a2
        jc short $-74
    }
}
