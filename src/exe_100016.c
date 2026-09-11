extern int __near mn6428;
extern int __near mn642A;
extern char __near mb4E9E;
void far helper_0(void);
void far helper_1(void);
int far exe_100016(int a)
{
    _asm {
        mov ax,mn6428
        cmp [bp+0x6],ax
        jnz short $+10
        mov ax,mn642A
        cmp [bp+0x8],ax
        jz short $+51
L10:
        test byte ptr mb4E9E,0x1
        jz short $+32
        call far ptr helper_0
        mov ax,[bp+0x6]
        mov mn6428,ax
        mov ax,[bp+0x8]
        mov mn642A,ax
        mov ax,0x1
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp short $+14
L35:
        mov ax,[bp+0x6]
        mov mn6428,ax
        mov ax,[bp+0x8]
        mov mn642A,ax
L41:
    }
}
