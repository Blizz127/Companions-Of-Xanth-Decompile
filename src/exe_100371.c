extern int __near mn644E;
extern int __near mn644C;
extern int __near mn644A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_100371(int a)
{
    _asm {
        sub sp,0x2
        les bx, [bp+0x6]
        mov ax,es:[bx]
        sub ax,mn644E
        sbb cx,cx
        and ax,cx
        add ax,mn644E
        mov [bp-0x2],ax
        push ax
        push word ptr mn644C
        push word ptr mn644A
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_0
        mov ax,[bp-0x2]
        sub dx,dx
        sub bx,bx
        mov cx,ax
        add mn644A,cx
        adc bx,dx
        mov cx,0xc
        shl bx,cl
        add mn644C,bx
        mov sp,bp
        pop bp
        retf 0x8
    }
}
