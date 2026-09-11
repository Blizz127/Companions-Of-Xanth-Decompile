extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb02F3;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
void far helper_10(void);
int far ovl_105472(int a)
{
    _asm {
        sub sp,0x10
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+124
        jmp L357
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L357
L1E:
        cmp word ptr mn6A04,0x77
        jz short $+78
        cmp word ptr mn6A04,0x78
        jz short $+71
        cmp word ptr mn6A02,0x76
        jnz short $+5
        jmp L357
L36:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x16
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L6A:
        mov ax,0x1
        jmp L359
        nop
L71:
        push word ptr mn6A02
        mov ax,0x77
        push ax
        mov ax,0x4
        push ax
        call far ptr helper_2
        add sp,0x6
        jmp L359
        nop
L89:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        mov [bp-0x2],ax
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L351
LA7:
        jna short $+5
        jmp L357
LAC:
        cmp al,0x2c
        jz short $+47
        ja short $+21
        sub al,0x8
        jz short $+41
        sub al,0x8
        jz short $+61
        sub al,0x3
        jnz short $+5
        jmp L1F9
LC1:
        jmp L357
        nop
LC5:
        sub al,0x38
        jnz short $+5
        jmp L22B
LCC:
        sub al,0x7
        jnz short $+5
        jmp L2B1
LD3:
        sub al,0x5
        jnz short $+5
        jmp L333
LDA:
        jmp L357
LDD:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xd
        jmp short $+52
        nop
LF5:
        mov ax,[bp-0x2]
        cmp ax,0x78
        jnz short $+5
        jmp L1B7
L100:
        jna short $+5
        jmp L6A
L105:
        or al,al
        jz short $+10
        sub al,0x76
        jz short $+44
        jmp L6A
        nop
L111:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x13
L126:
        mov dx,0xf030
        push dx
L12A:
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L6A
        nop
L137:
        mov ax,0x14
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        mov cx,0x76
        push cx
        call far ptr helper_4
        add sp,0x6
        mov ax,0x116
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov ax,0x5
        push ax
        mov ax,0x8
        push ax
        call far ptr helper_6
        add sp,0x4
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        or ax,ax
        jz short $+5
        jmp L6A
L191:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x3
        push ax
        call far ptr helper_9
        add sp,0x6
        jmp L6A
L1B7:
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        xor ax,ax
        push ax
        push ax
        mov ax,0x78
        push ax
        call far ptr helper_4
        add sp,0x6
        mov ax,0x116
        push ax
        push word ptr mn6A04
        call far ptr helper_5
L1F3:
        add sp,0x4
        jmp L6A
L1F9:
        cmp word ptr [bp-0x2],0x0
        jnz short $+12
        mov word ptr [bp-0x6],0x24ca
        mov word ptr [bp-0x4],ds
        jmp short $+23
L209:
        push word ptr [bp-0x2]
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x6],ax
        mov [bp-0x4],dx
L21E:
        push word ptr [bp-0x4]
        push word ptr [bp-0x6]
        mov ax,0xa
        jmp L126
        nop
L22B:
        cmp word ptr mn6A02,0x74
        jnz short $+17
        mov ax,0xe
L235:
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        jmp short $-76
L241:
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_7
        add sp,0x4
        or ax,ax
        jnz short $+30
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_7
        add sp,0x4
        or ax,ax
        jnz short $+10
        mov word ptr [bp-0xc],0x6f
        jmp short $+8
        nop
L271:
        mov word ptr [bp-0xc],0x69
L276:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0xc]
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0xf
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0xe
        jmp L6A
        nop
L2B1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x10
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,[bp-0x2]
        cmp ax,0x78
        jz short $+40
        ja short $+73
        or al,al
        jz short $+8
        sub al,0x76
        jz short $+20
        jmp short $+63
L2E7:
        mov ax,0x24ef
        push ds
L2EB:
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $+48
        nop
L2F7:
        mov ax,0x11
        mov dx,0xf030
        push dx
        jmp short $-19
        nop
L301:
        cmp byte ptr mb02F3,0x0
        jz short $+9
        mov ax,0x24fd
        mov dx,ds
        jmp short $+5
L30F:
        xor ax,ax
        cwd
L312:
        push dx
        push ax
        mov ax,0x12
        mov dx,0xf030
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
L324:
        mov ax,0x2e
        push ax
        call far ptr helper_10
        add sp,0x2
        jmp L6A
L333:
        cmp byte ptr mb02F3,0x0
        jz short $+11
        mov ax,0xb
        mov dx,0xf030
        jmp short $+8
        nop
L343:
        mov ax,0x24d3
        mov dx,ds
L348:
        push dx
        push ax
        mov ax,0x24e3
        push ds
        jmp L12A
L351:
        mov ax,0xc
        jmp L235
L357:
        xor ax,ax
L359:
    }
}
