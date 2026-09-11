extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern char __near mb030E;
extern int __near mn6A1E;
extern char __near mb5E34;
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
void far helper_11(void);
void far helper_12(void);
void far helper_13(void);
void far helper_14(void);
int far ovl_260732(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp L1E1
L12:
        jmp L417
L15:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L417
L20:
        mov ax,0xe
        push ax
        push word ptr mn6A02
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+39
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
L49:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        jmp L1DA
L59:
        mov ax,0x1
        push ax
        mov ax,0x145
        push ax
        call far ptr helper_3
        add sp,0x4
        mov [bp-0x4],ax
        or ax,ax
        jz short $+51
        mov ax,mn6A04
        cmp [bp-0x4],ax
        jnz short $+23
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x19
        jmp short $-65
        nop
L8D:
        mov ax,0x1a
L90:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        jmp L1DA
        nop
LA1:
        cmp word ptr mn6A04,0x149
        jnz short $+5
        jmp L15B
LAC:
        cmp word ptr mn6A04,0x14a
        jnz short $+5
        jmp L15B
LB7:
        cmp word ptr mn6A04,0x14b
        jnz short $+5
        jmp L15B
LC2:
        cmp word ptr mn6A04,0x14c
        jnz short $+5
        jmp L15B
LCD:
        cmp word ptr mn6A04,0x14d
        jnz short $+5
        jmp L15B
LD8:
        cmp word ptr mn6A04,0x4e
        jz short $+126
        cmp word ptr mn6A04,0xad
        jz short $+118
        cmp word ptr mn6A04,0x14e
        jz short $+110
        cmp word ptr mn6A04,0x6d
        jnz short $+45
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1c
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        xor ax,ax
        push ax
        jmp L1CD
        nop
        nop
        nop
L121:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0xc
        jmp L1DA
        nop
        nop
        nop
L15B:
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x2
        mov [bp-0x2],ax
        dec ax
        jnz short $+12
        mov word ptr [bp-0x8],0x3506
        mov word ptr [bp-0x6],ds
        jmp short $+23
L177:
        push word ptr [bp-0x2]
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        mov [bp-0x8],ax
        mov [bp-0x6],dx
L18C:
        push word ptr mn6A02
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1b
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x10
        mov ax,0x1
        push ax
        mov ax,0x145
L1CD:
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x6
L1DA:
        mov ax,0x1
        jmp L419
        nop
L1E1:
        mov ax,mn6A06
        cmp ax,0x13
        jnz short $+5
        jmp L321
L1EC:
        ja short $+11
        sub ax,0x8
        jz short $+34
        jmp L417
        nop
L1F7:
        sub ax,0x2c
        jnz short $+5
        jmp L387
L1FF:
        sub ax,0x18
        jnc short $+5
        jmp L417
L207:
        sub ax,0x1
        ja short $+5
        jmp L401
L20F:
        jmp L417
        nop
L213:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        jmp L49
L23F:
        cmp byte ptr mb030E,0x0
        jz short $+27
L246:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x12
        jmp L49
        nop
L25F:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        mov ax,0xe
        push ax
        mov ax,0x146
        push ax
        call far ptr helper_6
        add sp,0x4
        mov ax,0x2c
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0x14e
        push ax
        call far ptr helper_8
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x16
        jmp L90
L2CB:
        mov ax,0x1
        push ax
        mov ax,0x145
        push ax
        call far ptr helper_3
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L1DA
L2E2:
        mov ax,0x17
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0x145
        push ax
        call far ptr helper_3
        add sp,0x4
        mov mn6A1E,ax
        xor ax,ax
        push ax
        mov ax,0x20
        push ax
        call far ptr helper_9
        add sp,0x4
        call far ptr helper_10
L319:
        mov byte ptr mb5E34,0x0
        jmp L1DA
L321:
        mov ax,0xf
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+40
        mov ax,0x34fa
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        xor ax,ax
        push ax
        call far ptr helper_11
        add sp,0x2
        or ax,ax
        jz short $+25
        mov ax,0x10
        mov dx,0xf028
        push dx
        jmp short $+7
        nop
L36B:
        mov ax,0x34ff
        push ds
L36F:
        push ax
        call far ptr helper_2
        add sp,0x4
L378:
        mov ax,0x2e
        push ax
        call far ptr helper_12
        add sp,0x2
        jmp L1DA
L387:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        jmp L49
L3B3:
        cmp byte ptr mb030E,0x0
        jz short $+5
        jmp L246
L3BD:
        mov ax,0x13
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_13
        add sp,0x4
        mov ax,0xe
        push ax
        mov ax,0x146
        push ax
        call far ptr helper_13
        add sp,0x4
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        jmp L319
        nop
L401:
        xor ax,ax
        push ax
        mov ax,0x13f
        push ax
        push word ptr mn6A06
        call far ptr helper_14
        add sp,0x6
        jmp short $+5
        nop
L417:
        xor ax,ax
L419:
    }
}
