extern int __near mn4EA0;
extern char __near mb4E9E;
extern int __near mn642C;
extern int __near mn642E;
extern int __near mn6430;
extern int __near mn6432;
extern int __near mn642A;
extern int __near mn6428;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_99727(int a)
{
    _asm {
        mov word ptr mn4EA0,0x1
        mov al,mb4E9E
        and ax,0x1
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,[bp+0x6]
        mov mn642C,ax
        mov ax,[bp+0x8]
        mov mn642E,ax
        mov ax,[bp+0xa]
        mov mn6430,ax
        mov ax,[bp+0xc]
        mov mn6432,ax
        test byte ptr mb4E9E,0x1
        jz short $+26
        push word ptr mn642A
        push word ptr mn6428
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+7
        call far ptr helper_2
L4B:
        mov word ptr mn4EA0,0x0
    }
}
