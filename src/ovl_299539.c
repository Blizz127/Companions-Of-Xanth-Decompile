extern int __near mn02DE;
extern char __near mb036C;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_299539(int a)
{
    _asm {
        sub sp,0x4
        inc word ptr mn02DE
        mov ax,mn02DE
        dec ax
        jz short $+10
        dec ax
        jz short $+17
        dec ax
        jz short $+22
        jmp short $+30
L15:
        mov word ptr [bp-0x4],0x3922
        mov word ptr [bp-0x2],ds
        jmp short $+20
L1F:
        mov word ptr [bp-0x4],0x21
        jmp short $+8
        nop
L27:
        mov word ptr [bp-0x4],0x22
L2C:
        mov word ptr [bp-0x2],0xf046
L31:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x23
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        cmp word ptr mn02DE,0x3
        jnl short $+21
        mov ax,0x1
        push ax
        mov ax,0x24
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $+45
        nop
L61:
        mov ax,0xb
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_3
        add sp,0x2
        mov ax,0x5a01
        push ax
        mov ax,0x2ca
        push ax
        call far ptr helper_4
        mov byte ptr mb036C,0x1
L8B:
        mov ax,0x1
    }
}
