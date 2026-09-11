extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_83411(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+67
        jmp LF1
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LF1
L1A:
        cmp word ptr mn6A04,0x50
        jnz short $+8
        mov ax,0x49
        jmp short $+23
        nop
L27:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x4a
L3B:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
L45:
        mov sp,bp
L47:
        mov ax,0x1
        jmp LF3
L4D:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LD9
L58:
        jna short $+5
        jmp LF1
L5D:
        sub al,0x13
        jz short $+14
        sub al,0x16
        jz short $+50
        sub al,0x1b
        jz short $+108
        jmp LF1
        nop
L6D:
        mov ax,0x43
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        push word ptr mn6A04
        mov ax,0x50
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $-70
        mov ax,0x44
        jmp short $-87
        nop
L95:
        mov ax,0x45
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        push word ptr mn6A04
        mov ax,0x50
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+17
        mov ax,0x46
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
LC6:
        mov ax,0x2e
        push ax
        call far ptr helper_3
        jmp L45
        nop
LD3:
        mov ax,0x47
        jmp L3B
LD9:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x48
        jmp L3B
        nop
LF1:
        xor ax,ax
LF3:
    }
}
