extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_321391(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+71
        jmp LA1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA1
L1A:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xd
L40:
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp short $+84
L51:
        mov ax,mn6A06
        cmp ax,0x4f
        jz short $+68
        ja short $+72
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+26
        jmp short $+56
L6B:
        sub al,0x38
        jz short $+8
        sub al,0xd
        jz short $+22
        jmp short $+46
L75:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-52
        nop
L81:
        mov ax,0xb
        jmp short $-68
        nop
L87:
        xor ax,ax
        push ax
        mov ax,0x1d6
        push ax
        push word ptr mn6A06
        call far ptr helper_3
        mov sp,bp
        jmp short $+10
L9B:
        mov ax,0xc
        jmp short $-94
        nop
LA1:
        xor ax,ax
LA3:
    }
}
