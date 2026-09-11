extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb02F3;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_100686(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+118
        jmp L13D
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L13D
L1E:
        mov ax,0x11
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+25
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x14
        push ax
        call far ptr helper_1
        add sp,0x6
        jmp L13F
L49:
        push word ptr mn6A02
        mov ax,0x2
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
        mov ax,0x24
L70:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
L7D:
        mov ax,0x1
        jmp L13F
L83:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L137
L8E:
        jna short $+5
        jmp L13D
L93:
        cmp al,0x24
        jz short $+56
        ja short $+14
        sub al,0x8
        jz short $+26
        sub al,0xb
        jz short $+40
        jmp L13D
        nop
LA5:
        sub al,0x2c
        jz short $+14
        sub al,0x16
        jz short $+40
        sub al,0x2
        jz short $+92
        jmp L13D
        nop
LB5:
        mov ax,0x23
LB8:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        jmp short $-72
LC7:
        mov ax,0x1c
        jmp short $-18
        nop
LCD:
        mov ax,0x22
        jmp short $-24
        nop
LD3:
        cmp byte ptr mb02F3,0x0
        jz short $+9
        mov ax,0x2465
        mov dx,ds
        jmp short $+8
LE1:
        mov ax,0x21
        mov dx,0xf009
LE7:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x20
        jmp L70
L10B:
        cmp byte ptr mb02F3,0x0
        jz short $+7
        xor ax,ax
        cwd
        jmp short $+8
L117:
        mov ax,0x1e
        mov dx,0xf009
L11D:
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        jmp L70
L137:
        mov ax,0x1f
        jmp LB8
L13D:
        xor ax,ax
L13F:
    }
}
