extern char __near mb416E;
extern int __near mn4196;
extern int __near mn4232;
extern int __near mn6A1C;
extern int __near mn6A1A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_11917(int a)
{
    _asm {
        call far ptr helper_0
        mov ax,[bp+0x6]
        dec ax
        jz short $+20
        dec ax
        jz short $+97
        dec ax
        jnz short $+5
        jmp LC1
L14:
        dec ax
        jnz short $+5
        jmp L103
L1A:
        jmp L14C
L1D:
        call far ptr helper_1
        call far ptr helper_2
        mov al,mb416E
        and ax,0x6
        push ax
        mov ax,0x26
        push ax
        mov ax,0xa5
        push ax
        call far ptr helper_3
        mov sp,bp
        test byte ptr mb416E,0x6
        jnz short $+5
        jmp L14C
L47:
        test byte ptr mb416E,0x8
        jnz short $+5
        jmp L14C
L51:
        cmp word ptr mn4196,0x4
        jnz short $+5
        jmp L14C
L5B:
        call far ptr helper_4
        mov al,mb416E
        and ax,0x8
        push ax
        mov ax,0x4c
        jmp L13F
L6D:
        call far ptr helper_4
        mov al,mb416E
        and ax,0x8
        push ax
        mov ax,0x4c
        push ax
        mov ax,0xa5
        push ax
        call far ptr helper_3
        add sp,0x6
        test byte ptr mb416E,0x6
        jnz short $+5
        jmp L14C
L93:
        test byte ptr mb416E,0x8
        jnz short $+5
        jmp L14C
L9D:
        cmp word ptr mn4196,0x4
        jnz short $+5
        jmp L14C
LA7:
        call far ptr helper_1
        call far ptr helper_2
        mov al,mb416E
        and ax,0x6
        push ax
        mov ax,0x26
        jmp L13F
        nop
        nop
        nop
LC1:
        cmp word ptr mn4232,0x0
        jnz short $+5
        jmp L14C
LCB:
        cmp word ptr mn6A1C,0x1
        sbb ax,ax
        neg ax
        mov mn6A1C,ax
        push ax
        mov ax,0x65
        push ax
        mov ax,0xa5
        push ax
        call far ptr helper_3
        add sp,0x6
        cmp word ptr mn6A1C,0x0
        jnz short $+95
        cmp word ptr mn6A1A,0x0
        jnz short $+88
        mov ax,0x1
        mov mn6A1A,ax
        push ax
        mov ax,0x79
        jmp short $+63
        nop
L103:
        cmp word ptr mn4232,0x0
        jz short $+68
        cmp word ptr mn6A1A,0x1
        sbb ax,ax
        neg ax
        mov mn6A1A,ax
        push ax
        mov ax,0x79
        push ax
        mov ax,0xa5
        push ax
        call far ptr helper_3
        add sp,0x6
        cmp word ptr mn6A1A,0x0
        jnz short $+32
        cmp word ptr mn6A1C,0x0
        jnz short $+25
        mov ax,0x1
        mov mn6A1C,ax
        push ax
        mov ax,0x65
L13F:
        push ax
        mov ax,0xa5
        push ax
        call far ptr helper_3
        add sp,0x6
L14C:
        call far ptr helper_5
    }
}
