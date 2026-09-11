extern char __near mb69B8;
extern int __near mn69B4;
extern int __near mn69B6;
extern int __near mn69B2;
extern int __near mn69AE;
void far helper_0(void);
void far helper_1(void);
int far exe_14952(int a)
{
    _asm {
        mov byte ptr mb69B8,0x42
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov mn69B4,ax
        mov mn69B6,dx
        mov si,0x69ae
        mov [si],ax
        mov [si+0x2],dx
        mov word ptr mn69B2,0x7fff
        push word ptr [bp+0x10]
        push word ptr [bp+0xe]
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push ds
        push si
        call far ptr helper_0
        add sp,0xc
        mov di,ax
        dec word ptr mn69B2
        js short $+17
        les bx, mn69AE
        inc word ptr mn69AE
        mov byte ptr es:[bx],0x0
        jmp short $+16
        nop
lbl4F:
        push ds
        push si
        xor ax,ax
        push ax
        call far ptr helper_1
        add sp,0x6
lbl5C:
        mov ax,di
    }
}
