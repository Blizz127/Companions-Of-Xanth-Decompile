extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_318697(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+107
        jmp LE1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+10
        sub ax,0x10
        jz short $+5
        jmp LE1
L1F:
        mov ax,mn6A04
        sub ax,0x1c3
        jz short $+58
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x6
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
L57:
        mov sp,bp
L59:
        mov ax,0x1
        jmp LE3
L5F:
        mov ax,0x1d2
        push ax
        push word ptr mn6A04
        mov ax,0x48
        push ax
        call far ptr helper_2
        mov sp,bp
        jmp short $+113
        nop
L75:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+34
        ja short $+100
        sub al,0x7
        jz short $+16
        dec al
        jz short $+24
        sub al,0xb
        jz short $+32
        sub al,0x19
        jz short $+16
        jmp short $+82
L91:
        mov ax,0x1
        push ax
        call far ptr helper_3
        jmp short $-67
        nop
L9D:
        push word ptr mn6A04
        call far ptr helper_4
        jmp short $-79
        nop
LA9:
        mov ax,0x4
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1ce
        push ax
        mov ax,0x1c3
        push ax
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $-114
        mov ax,0x5
        mov dx,0xf04a
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L59
        nop
LE1:
        xor ax,ax
LE3:
    }
}
