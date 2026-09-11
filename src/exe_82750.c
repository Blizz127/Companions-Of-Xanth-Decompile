extern int __near mn4244;
extern char __near mb46B5;
extern char __near mb46B6;
extern int __near mn425A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_82750(int a)
{
    _asm {
        mov ax,[bp+0x6]
        mov mn4244,ax
        mov cx,0x4246
        push ds
        push cx
        call far ptr helper_0
        add sp,0x4
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x2
        mov ax,0x46b4
        mov cx,0x3420
        mov dx,0x38af
        mov bx,cx
        push ds
        mov di,ax
        mov si,0x6a54
        mov es,cx
        mov ds,dx
        mov cx,0x18
        rep movsw
        pop ds
        mov es,bx
        mov si,ax
        mov al,0x3f
        mov es:[si],al
        mov es:mb46B5,al
        mov byte ptr es:mb46B6,0x0
        cmp word ptr mn425A,0x0
        jnz short $+21
        mov ax,0xb8b1
        mov dx,0x8a7
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov mn425A,ax
lbl68:
    }
}
