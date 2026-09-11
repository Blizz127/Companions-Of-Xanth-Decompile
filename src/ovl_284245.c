extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_284245(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+76
        jmp LEB
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LEB
L1E:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x17
L45:
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L52:
        mov ax,0x1
        jmp LED
        nop
L59:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LE5
L64:
        jna short $+5
        jmp LEB
L69:
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+58
        sub al,0x19
        jz short $+10
        sub al,0x18
        jz short $+68
        jmp short $+114
        nop
        nop
L7D:
        cmp word ptr mn6A06,0x8
        jnz short $+9
        mov ax,0x3716
        mov dx,ds
        jmp short $+5
L8B:
        xor ax,ax
        cwd
L8E:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x15
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $-84
        nop
LA9:
        mov ax,0x13
LAC:
        mov dx,0xf040
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $-103
LBB:
        mov ax,0x175
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        jmp L45
LE5:
        mov ax,0x16
        jmp short $-60
        nop
LEB:
        xor ax,ax
LED:
    }
}
