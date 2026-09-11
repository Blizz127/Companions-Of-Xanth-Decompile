extern int __near mn6E10;
extern int __near mn5B4E;
void far helper_0(void);
int far exe_103458(int a)
{
    _asm {
        sub sp,0x306
        xor ax,ax
        mov mn6E10,ax
        mov [bp-0x2],ax
L0C:
        mov word ptr [bp-0x4],0x0
        lea ax,[bp-0x304]
        mov [bp-0x306],ax
        mov es, mn5B4E
L1D:
        mov bx,[bp-0x4]
        mov al,es:[bx+0x6a24]
        cbw
        imul word ptr [bp-0x2]
        cwd
        and dx,0x3f
        add ax,dx
        mov cx,0x6
        sar ax,cl
        mov bx,[bp-0x306]
        inc word ptr [bp-0x306]
        mov [bx],al
        inc word ptr [bp-0x4]
        lea ax,[bp-0x4]
        cmp [bp-0x306],ax
        jc short $-43
        lea ax,[bp-0x304]
        push ss
        push ax
        call far ptr helper_0
        add sp,0x4
        add word ptr [bp-0x2],0x4
        cmp word ptr [bp-0x2],0x40
        jng short $-84
    }
}
