extern int __near mn6A04;
extern int __near mn1AI;
extern int __near mn25I;
extern int __near mn5AB6;
extern int __near mn95I;
extern int __near mn6A02;
extern int __near mnAFI;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_58697(int a)
{
    _asm {
        sub sp,0x6
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp lblFF
lbl1A:
        cmp word ptr mn6A04, offset mn1AI
        jnz short $+5
        jmp lblFF
lbl25:
        cmp word ptr mn6A04, offset mn25I
        jnz short $+5
        jmp lblFF
lbl30:
        mov ax,0xc
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+59
        mov ax,0x7
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+39
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        jmp short $+127
        nop
lbl7D:
        mov word ptr [bp-0x4],0x3c
lbl82:
        mov ax,mn6A04
        mov es, mn5AB6
        mov bx,[bp-0x4]
        cmp es:[bx],ax
        jz short $+112
        add word ptr [bp-0x4],0x2
        cmp word ptr [bp-0x4], offset mn95I
        jc short $-24
        mov word ptr [bp-0x6],0x1db0
lblA1:
        mov ax,mn6A02
        mov bx,[bp-0x6]
        cmp [bx],ax
        jz short $+86
        add word ptr [bp-0x6],0x2
        cmp word ptr [bp-0x6], offset mnAFI
        jc short $-19
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x10
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_3
        add sp,0x10
lblF9:
        mov ax,0x1
        jmp short $+5
        nop
lblFF:
        xor ax,ax
lbl101:
    }
}
