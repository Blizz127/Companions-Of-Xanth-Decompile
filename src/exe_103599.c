extern int __near mn42E8;
extern int __near mn6E10;
extern int __near mn5B4E;
void far helper_0(void);
void far helper_1(void);
int far exe_103599(int a)
{
    _asm {
        sub sp,0x306
        cmp word ptr mn42E8,0x0
        jnz short $+100
        mov word ptr mn6E10,0x0
        mov word ptr [bp-0x2],0x40
L16:
        mov word ptr [bp-0x4],0x0
        lea ax,[bp-0x304]
        mov [bp-0x306],ax
        mov es, mn5B4E
L27:
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
        sub word ptr [bp-0x2],0x4
        jns short $-80
        call far ptr helper_1
L6D:
    }
}
