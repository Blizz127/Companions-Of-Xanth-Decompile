extern char __near mb0298;
extern char __near mb0299;
extern int __near mn0256;
extern int __near mn0294;
extern int __near mn0290;
extern int __near mn0296;
extern int __near mn5A8C;
extern int __near mn00EC;
extern int __near mn028C;
extern char __near mb1D00;
void far helper_0(void);
void far helper_1(void);
int far ovl_33740(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jl short $+90
        jo short $+88
        dec ax
        jg short $+85
        cmp word ptr [bp+0x8],0x0
        jnz short $+9
        mov byte ptr mb0298,0x1
        jmp short $+7
lbl1B:
        mov byte ptr mb0299,0x1
lbl20:
        mov ax,mn0256
        mov mn0294,ax
        mov ax,mn0290
        mov mn0296,ax
        mov es, mn5A8C
        mov ax,0x3420
        push ds
        mov di,0x1356
        mov si,0x32
        mov ds,ax
        mov cx,0x20
        rep movsw
        pop ds
        mov ax,mn00EC
        mov mn028C,ax
        call far ptr helper_0
        xor ax,ax
        push ax
        mov ax,0x17
        push ax
        call far ptr helper_1
        add sp,0x4
        mov byte ptr mb1D00,0x0
lbl61:
    }
}
