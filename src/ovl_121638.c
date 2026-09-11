extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_121638(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp LCF
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L9D
L16:
        jna short $+5
        jmp LCF
L1B:
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+36
        sub al,0x19
        jz short $+10
        sub al,0x18
        jz short $+58
        jmp LCF
        nop
L2F:
        mov ax,0x1e
L32:
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
L3C:
        mov sp,bp
        mov ax,0x1
        jmp LD1
        nop
L45:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+7
        mov ax,0x1a
        jmp short $-41
L5D:
        mov ax,0x1b
        jmp short $-46
        nop
L63:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x1c
        jmp short $-71
L7B:
        mov ax,0x1d
        mov dx,0xf00d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-94
        nop
L9D:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jnz short $+9
        mov ax,0x1f
        jmp L32
        nop
LB7:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_3
        mov sp,bp
        push dx
        push ax
        mov ax,0x20
        jmp L32
        nop
LCF:
        xor ax,ax
LD1:
    }
}
