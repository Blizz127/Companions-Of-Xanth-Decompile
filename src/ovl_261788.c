extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_261788(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+40
        jmp LD9
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LD9
L1E:
        mov ax,0x144
        push ax
        push word ptr mn6A04
L26:
        push word ptr mn6A06
        call far ptr helper_0
        add sp,0x6
        jmp LDB
L35:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LD1
L40:
        jna short $+5
        jmp LD9
L45:
        sub al,0x8
        jz short $+14
        sub al,0xb
        jz short $+20
        sub al,0x19
        jz short $+112
        jmp LD9
        nop
L55:
        xor ax,ax
        push ax
        mov ax,0x144
L5B:
        push ax
        jmp short $-54
        nop
L5F:
        xor ax,ax
        push ax
        call far ptr helper_1
        add sp,0x2
        or ax,ax
        jz short $+33
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_3
        add sp,0x4
        jmp short $+7
L8D:
        mov ax,0x3513
        mov dx,ds
L92:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_3
        add sp,0x4
        push dx
        push ax
        mov ax,0x351c
        push ds
        push ax
        call far ptr helper_4
        add sp,0xc
LB9:
        mov ax,0x1
        jmp short $+31
        nop
LBF:
        mov ax,0x1e
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_4
        add sp,0x4
        jmp short $-22
LD1:
        xor ax,ax
        push ax
        mov ax,0x13f
        jmp short $-124
LD9:
        xor ax,ax
LDB:
    }
}
