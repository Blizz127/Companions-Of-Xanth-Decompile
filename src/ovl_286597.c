extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_286597(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+58
        jmp LDB
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LDB
L1E:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        mov dx,0xf02c
        push dx
L37:
        push ax
        call far ptr helper_1
        add sp,0x8
L40:
        mov ax,0x1
        jmp LDD
        nop
L47:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+122
        jna short $+5
        jmp LDB
L54:
        sub al,0x13
        jz short $+9
        sub al,0x7
        jz short $+93
        jmp short $+127
        nop
L5F:
        mov ax,0x5
        mov dx,0xf02c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,mn0256
        sub ax,0x178
        jz short $+18
        dec ax
        dec ax
        jz short $+22
        dec ax
        dec ax
        jz short $+26
        sub ax,0x3
        jz short $+29
        jmp short $+37
        nop
L87:
        mov word ptr [bp-0x4],0x6
        jmp short $+24
        nop
L8F:
        mov word ptr [bp-0x4],0x7
        jmp short $+16
        nop
L97:
        mov word ptr [bp-0x4],0x8
        jmp short $+8
        nop
L9F:
        mov word ptr [bp-0x4],0x9
LA4:
        mov word ptr [bp-0x2],0xf02c
LA9:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x3753
        push ds
        jmp short $-124
        nop
        nop
LB7:
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x2
        jmp L40
        nop
LC7:
        mov ax,0xa
        mov dx,0xf02c
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L40
        nop
LDB:
        xor ax,ax
LDD:
    }
}
