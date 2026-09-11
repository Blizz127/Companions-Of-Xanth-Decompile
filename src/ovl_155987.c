extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_155987(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+73
        jmp LE5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LE5
L1A:
        push word ptr mn6A04
        mov ax,0x26
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x5e
L40:
        mov dx,0xf008
        push dx
        push ax
        call far ptr helper_1
L4A:
        mov sp,bp
        mov ax,0x1
        jmp LE7
        nop
L53:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp LDF
L5E:
        jna short $+5
        jmp LE5
L63:
        cmp al,0x2c
        jz short $+26
        ja short $+14
        sub al,0x8
        jz short $+20
        sub al,0xb
        jz short $+28
        jmp short $+116
        nop
        nop
L75:
        sub al,0x38
        jz short $+26
        sub al,0xc
        jz short $+94
        jmp short $+104
L7F:
        push word ptr mn6A04
        call far ptr helper_2
        jmp short $-62
        nop
L8B:
        mov ax,0x5a
        jmp short $-78
        nop
L91:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x8
        push ax
        push word ptr mn6A02
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jz short $+7
        mov ax,0x2aed
        jmp short $+5
LBB:
        mov ax,0x2af2
LBE:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x5d
        jmp L40
        nop
LD9:
        mov ax,0x5b
        jmp L40
LDF:
        mov ax,0x5c
        jmp L40
LE5:
        xor ax,ax
LE7:
    }
}
