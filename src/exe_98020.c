extern int __near mn4E9E;
extern int __near mn643C;
extern int __near mn643E;
extern int __near mn6440;
extern int __near mn6442;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far exe_98020(int a)
{
    _asm {
        sub sp,0x8
        cmp word ptr mn4E9E,0x0
        jz short $+5
        jmp LC8
L0D:
        mov ax,0x33
        push ax
        call far ptr helper_0
        add sp,0x2
        mov es,dx
        mov bx,ax
        mov [bp-0x4],ax
        mov word ptr [bp-0x2],es
        mov al,es:[bx]
        mov [bp-0x8],al
        mov cx,dx
        or cx,bx
        jz short $+6
        cmp al,0xcf
        jnz short $+30
L33:
        mov ax,0x4ea2
        push ds
        push ax
        mov ax,0x5438
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        call far ptr helper_2
        call far ptr helper_3
L4F:
        mov ax,0x20
        int 0x33
        mov ax,0x0
        int 0x33
        mov [bp-0x6],ax
        cmp word ptr [bp-0x6],-1
        jz short $+40
        xor ax,ax
        push ax
        call far ptr helper_4
        mov ax,0x4ec1
        push ds
        push ax
        mov ax,0x5438
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        push ax
        call far ptr helper_5
        add sp,0x2
L88:
        mov word ptr mn4E9E,0x80
        mov ax,0x100
        cwd
        push dx
        push ax
        call far ptr helper_6
        add sp,0x4
        mov mn643C,ax
        mov mn643E,dx
        mov ax,0x100
        cwd
        push dx
        push ax
        call far ptr helper_6
        add sp,0x4
        mov mn6440,ax
        mov mn6442,dx
        call far ptr helper_7
        cmp word ptr [bp+0x6],0x0
        jz short $+7
        call far ptr helper_8
LC8:
    }
}
