extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn02EA;
extern int __near mn02EC;
extern char __near mb02EC;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_178459(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+55
        jmp L121
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L121
L1A:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x46
L2E:
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
L38:
        mov sp,bp
        mov ax,0x1
        jmp L123
        nop
L41:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L109
L4C:
        jna short $+5
        jmp L121
L51:
        sub al,0x13
        jz short $+16
        sub al,0x16
        jz short $+18
        sub al,0x1b
        jnz short $+5
        jmp LF1
L60:
        jmp L121
L63:
        mov ax,0x42
        jmp short $-56
        nop
L69:
        mov ax,0x45
        mov dx,0xf00b
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        cmp word ptr mn02EA,0x7
        jnz short $+16
        mov word ptr mn02EA,0x8
        mov word ptr mn02EC,0x4
        jmp short $+14
L8D:
        mov word ptr mn02EA,0x7
        mov word ptr mn02EC,0x0
L99:
        mov cl,mb02EC
        mov ax,0x1
        shl ax,cl
        mov bx,mn02EA
        add bx,bx
        or [bx+0x2c7e],ax
        mov ax,0x12
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+35
        mov ax,0x12
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_4
        mov sp,bp
LE0:
        mov ax,0x16
        push ax
        push word ptr mn0256
        call far ptr helper_5
        jmp L38
        nop
LF1:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x43
        jmp L2E
L109:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x44
        jmp L2E
L121:
        xor ax,ax
L123:
    }
}
