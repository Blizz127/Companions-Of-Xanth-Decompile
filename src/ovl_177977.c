extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb032D;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_177977(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LE9
L0F:
        jmp L1D9
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L1D9
L1E:
        mov ax,mn6A04
        sub ax,0x58
        jz short $+23
        mov ax,0x41
L29:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_0
L33:
        mov sp,bp
L35:
        mov ax,0x1
        jmp L1DB
L3B:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+7
        mov ax,0x3e
        jmp short $-40
L53:
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+43
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3f
        jmp short $-99
        nop
L8F:
        mov ax,0x40
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        push word ptr mn6A02
        push word ptr mn6A04
        call far ptr helper_4
        mov sp,bp
        mov ax,0x12
        push ax
        mov ax,0xd4
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+5
        jmp L35
LC7:
        mov ax,0x12
        push ax
        mov ax,0xd4
        push ax
        call far ptr helper_5
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_6
        jmp L33
LE9:
        mov ax,mn6A06
        cmp ax,0x49
        jnz short $+5
        jmp L179
LF4:
        jna short $+5
        jmp L1D9
LF9:
        cmp al,0x2c
        jz short $+28
        ja short $+14
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+24
        jmp L1D9
        nop
L10B:
        sub al,0x44
        jz short $+80
        dec al
        jz short $+82
        jmp L1D9
        nop
L117:
        mov ax,0x39
        jmp L29
L11D:
        mov ax,0x35
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        push word ptr mn6A04
        mov ax,0x58
        push ax
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+5
        jmp L35
L142:
        cmp byte ptr mb032D,0x0
        jz short $+10
        mov ax,0x37
        mov dx,0xf00b
        jmp short $+5
L151:
        xor ax,ax
        cwd
L154:
        push dx
        push ax
        mov ax,0x36
        jmp L29
        nop
L15D:
        mov ax,0x38
        jmp L29
L163:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        mov ax,0x3a
        jmp short $+57
L179:
        push word ptr mn6A04
        mov ax,0x58
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+54
        cmp byte ptr mb032D,0x0
        jz short $+9
        mov ax,0x3b
        jmp L29
        nop
L19B:
        mov ax,0x58
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
L1B0:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp L35
        nop
L1C1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x3d
        jmp short $-38
        nop
L1D9:
        xor ax,ax
L1DB:
    }
}
