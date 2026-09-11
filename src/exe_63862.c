extern char __near mb416E;
extern int __near mn4176;
extern int __near mn4168;
extern int __near mn415A;
extern int __near mn416C;
extern int __near mn5A5C;
extern int __near mn4124;
extern int __near mn412C;
extern int __near mn4166;
extern int __near mn4158;
extern int __near mn416A;
extern int __near mn4178;
extern int __near mn417C;
extern int __near mn417A;
extern int __near mn4162;
extern int __near mn4164;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_63862(int a)
{
    _asm {
        sub sp,0xa
        test byte ptr mb416E,0x6
        jnz short $+5
        jmp L124
L0D:
        test byte ptr [bp+0x7],0xff
        jz short $+16
        mov word ptr [bp-0x4],0x0
        mov ax,[bp+0x6]
        mov [bp-0x6],ax
        jmp short $+14
        nop
L21:
        mov ax,[bp+0x6]
        mov [bp-0x4],ax
        mov word ptr [bp-0x6],0x0
L2C:
        cmp word ptr mn4176,0x0
        jnz short $+15
        cmp word ptr mn4168,0x0
        jz short $+8
        mov ax,[bp+0x8]
        mov mn4168,ax
L40:
        test byte ptr mb416E,0x60
        jz short $+36
        cmp word ptr [bp-0x4],0x0
        jz short $+13
        mov ax,mn415A
        cmp [bp-0x4],ax
        jnz short $+5
        jmp L124
L58:
        cmp word ptr [bp-0x6],0x0
        jz short $+13
        mov ax,mn416C
        cmp [bp-0x6],ax
        jnz short $+5
        jmp L124
L69:
        mov ax,0xffff
        push ax
        call far ptr helper_0
        add sp,0x2
        cmp word ptr [bp-0x4],0x0
        jz short $+96
        mov word ptr [bp-0x8],0x0
        mov cl,0x3
        mov ax,[bp-0x4]
        shl ax,cl
        add ax,0x83a
        mov [bp-0xa],ax
L8D:
        mov bx,[bp-0xa]
        mov es, mn5A5C
        mov ax,es:[bx]
        mov bx,[bp-0x8]
        mov [bx+0x4124],ax
        push ax
        call far ptr helper_1
        mov bx,[bp-0x8]
        add sp,0x2
        mov [bx+0x412c],ax
        add word ptr [bp-0xa],0x2
        add word ptr [bp-0x8],0x2
        cmp word ptr [bp-0x8],0x8
        jl short $-45
        mov ax,[bp-0x4]
        mov mn415A,ax
        mov ax,mn4124
        mov mn416C,ax
        mov ax,mn412C
        mov mn4166,ax
        xor ax,ax
        mov mn4158,ax
        mov mn416A,ax
        jmp short $+36
        nop
LD9:
        xor ax,ax
        mov mn415A,ax
        mov mn4158,ax
        mov ax,[bp-0x6]
        mov mn416C,ax
        mov cx,[bp+0xa]
        mov mn416A,cx
        push ax
        call far ptr helper_1
        add sp,0x2
        mov mn4166,ax
LFA:
        mov word ptr mn4176,0x0
        mov word ptr mn4178,0x7f
        sub ax,ax
        mov mn417C,ax
        mov mn417A,ax
        mov ax,[bp+0x8]
        mov mn4162,ax
        mov mn4168,ax
        call far ptr helper_2
        mov mn4164,ax
        call far ptr helper_3
L124:
    }
}
