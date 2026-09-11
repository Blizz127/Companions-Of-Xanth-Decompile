extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_296403(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+37
        jmp LC3
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC3
L1A:
        xor ax,ax
        push ax
        push word ptr mn6A02
        mov ax,0x31
        push ax
        call far ptr helper_0
        mov sp,bp
        jmp LC5
L2F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+100
        jna short $+5
        jmp LC3
L3C:
        cmp al,0x2c
        jz short $+29
        ja short $+13
        sub al,0x8
        jz short $+23
        sub al,0xb
        jz short $+57
        jmp short $+121
        nop
L4D:
        sub al,0x31
        jz short $+56
        sub al,0x7
        jz short $+58
        sub al,0xc
        jz short $+54
        jmp short $+106
L5B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x1f
L6F:
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_2
L79:
        mov sp,bp
        mov ax,0x1
        jmp short $+71
        nop
L81:
        mov ax,0x1e
        jmp short $-21
        nop
L87:
        mov ax,0x21
        jmp short $-27
        nop
L8D:
        push word ptr mn6A04
        call far ptr helper_3
        jmp short $-29
        nop
L99:
        mov ax,0x20
        mov dx,0xf02b
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1388
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x5a1c
        push ax
        mov ax,0x250
        push ax
        call far ptr helper_5
        jmp short $-71
        nop
LC3:
        xor ax,ax
LC5:
    }
}
