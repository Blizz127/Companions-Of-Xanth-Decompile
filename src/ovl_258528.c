extern int __near mn5B26;
extern int __near mn02D0;

int far ovl_258528(int a)
{
    _asm {
        sub sp,0x4
        mov word ptr [bp-0x2],0x0
        mov word ptr [bp-0x4],0x3498
L0D:
        mov ax,[bp+0x6]
        mov bx,[bp-0x4]
        cmp [bx],ax
        jz short $+18
        inc word ptr [bp-0x2]
        add word ptr [bp-0x4],0x2
        cmp word ptr [bp-0x4],0x34a2
        jc short $-22
        jmp short $+30
L27:
        mov es, mn5B26
        mov cl,0x4
        mov bx,mn02D0
        mov ax,bx
        add bx,bx
        add bx,bx
        add bx,ax
        add bx,[bp-0x2]
        shl bx,cl
        mov al,es:[bx+0x5c0]
L43:
    }
}
