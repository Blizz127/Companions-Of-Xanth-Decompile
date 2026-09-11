extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
extern char __near mb0343;
extern int __near mn0256;
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
int far ovl_114529(int a)
{
    _asm {
        sub sp,0xe
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+12
        dec ax
        dec ax
        jnz short $+5
        jmp LC7
L12:
        jmp L8D3
L15:
        mov ax,mn6A06
        cmp ax,0x38
        jz short $+18
        jna short $+5
        jmp L8D3
L22:
        sub al,0x4
        jz short $+9
        sub al,0x2f
        jz short $+29
        jmp L8D3
L2D:
        push word ptr mn6A04
        push word ptr mn6A02
L35:
        mov ax,0x14
L38:
        push ax
        call far ptr helper_0
        add sp,0x6
        jmp L8D5
        nop
L45:
        mov ax,mn6A04
        sub ax,0x88
        jl short $+118
        jo short $+116
        dec ax
        jng short $+9
        sub ax,0x12
        jz short $+56
        jmp short $+106
L59:
        mov ax,mn6A04
        cmp mn6A02,ax
        jnz short $+7
        mov ax,0x25eb
        jmp short $+5
L67:
        mov ax,0x25f2
L6A:
        push ds
        push ax
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x2
        cmp ax,0x122
        jnz short $+8
        mov ax,0x25fa
        jmp short $+6
        nop
L83:
        mov ax,0x2602
L86:
        push ds
        push ax
        mov ax,0x37
        jmp short $+41
L8D:
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
        mov ax,0x36
LB4:
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
LC1:
        mov ax,0x1
        jmp L8D5
LC7:
        mov ax,mn6A06
        cmp ax,0x53
        jnz short $+5
        jmp L8BB
LD2:
        jna short $+5
        jmp L8D3
LD7:
        cmp al,0x2c
        jz short $+54
        ja short $+20
        sub al,0x8
        jz short $+48
        sub al,0xb
        jz short $+126
        dec al
        jnz short $+5
        jmp L21F
LEC:
        jmp L8D3
LEF:
        sub al,0x33
        jnz short $+5
        jmp L517
LF6:
        sub al,0x5
        jnz short $+5
        jmp L71F
LFD:
        sub al,0xc
        jnz short $+5
        jmp L765
L104:
        dec al
        jnz short $+5
        jmp L83D
L10B:
        jmp L8D3
        nop
L10F:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x30
        jmp short $+24
        nop
L13B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x31
L150:
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        jmp LC1
        nop
L161:
        mov ax,0x86
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+34
        mov ax,0x87
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+14
        mov word ptr [bp-0x8],0x10
        mov word ptr [bp-0x6],0xf00c
        jmp short $+10
L195:
        sub ax,ax
        mov [bp-0x6],ax
        mov [bp-0x8],ax
L19D:
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        mov ax,0xf
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x2
        cmp ax,0x122
        jnz short $+5
        jmp LC1
L1C7:
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x2
        sub ax,0x146
        jz short $+13
        dec ax
        jz short $+40
        sub ax,0x3
        jz short $+43
        jmp short $+51
        nop
L1E3:
        cmp byte ptr mb0343,0x0
        jz short $+11
        mov ax,0x12
        mov dx,0xf00c
        jmp short $+8
        nop
L1F3:
        mov ax,0x25d5
        mov dx,ds
L1F8:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        jmp short $+21
        nop
L201:
        mov word ptr [bp-0x4],0x13
        jmp short $+8
        nop
L209:
        mov word ptr [bp-0x4],0x11
L20E:
        mov word ptr [bp-0x2],0xf00c
L213:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x14
        jmp L150
L21F:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1e
        jmp L150
L24B:
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x2
        sub ax,0x122
        jz short $+27
        sub ax,0x24
        jnz short $+5
        jmp L3C3
L264:
        dec ax
        jnz short $+5
        jmp L45D
L26A:
        sub ax,0x3
        jnz short $+5
        jmp L463
L272:
        jmp LC1
L275:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x29
        jmp L150
L2A1:
        cmp word ptr mn6A02,0x6e
        jnz short $+5
        jmp L373
L2AB:
        cmp word ptr mn6A02,0x6f
        jnz short $+5
        jmp L373
L2B5:
        cmp word ptr mn6A02,0x7f
        jnz short $+5
        jmp L373
L2BF:
        cmp word ptr mn6A02,0x17
        jnz short $+5
        jmp L373
L2C9:
        cmp word ptr mn6A02,0x76
        jnz short $+67
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A02
        call far ptr helper_5
        add sp,0x6
        or ax,ax
        jnz short $+8
L2E7:
        mov ax,0x26
        jmp L506
L2ED:
        mov ax,0x2c
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_6
        add sp,0x6
        jmp L4CE
        nop
L311:
        cmp word ptr mn6A02,0x9b
        jnz short $+18
        call far ptr helper_7
        or ax,ax
        jz short $+9
        mov ax,0x2d
        jmp L506
        nop
L329:
        cmp word ptr mn6A02,0x77
        jnz short $+27
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2e
        jmp L150
        nop
L349:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2f
        jmp LB4
L373:
        cmp word ptr mn6A02,0x17
        jnz short $+35
        cmp word ptr mn0256,0x80
        jnz short $+27
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2a
        jmp L150
        nop
L39B:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x2b
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        mov ax,0x14a
        jmp L4DD
L3C3:
        cmp word ptr mn6A02,0x76
        jnz short $+9
        mov ax,0x20
        jmp L506
        nop
L3D1:
        cmp word ptr mn6A02,0x6e
        jz short $+79
        cmp word ptr mn6A02,0x6f
        jz short $+72
        cmp word ptr mn6A02,0x7f
        jz short $+65
        cmp word ptr mn6A02,0x17
        jz short $+58
        cmp word ptr mn6A02,0x77
        jnz short $+9
        mov ax,0x23
        jmp L506
        nop
L3FB:
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x24
        jmp LB4
L425:
        cmp byte ptr mb0343,0x0
        jz short $+9
        mov ax,0x21
        jmp L506
        nop
L433:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x22
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        mov byte ptr mb0343,0x1
        jmp LC1
L45D:
        mov ax,0x1f
        jmp L506
L463:
        cmp word ptr mn6A02,0x6e
        jnz short $+5
        jmp L503
L46D:
        cmp word ptr mn6A02,0x6f
        jnz short $+5
        jmp L503
L477:
        cmp word ptr mn6A02,0x7f
        jnz short $+5
        jmp L503
L481:
        cmp word ptr mn6A02,0x17
        jz short $+125
        cmp word ptr mn6A02,0x76
        jnz short $+94
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr mn6A02
        call far ptr helper_5
        add sp,0x6
        or ax,ax
        jnz short $+5
        jmp L2E7
L4A9:
        mov ax,0x27
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0x76
        push ax
        call far ptr helper_6
        add sp,0x6
        mov byte ptr mb0343,0x1
L4CE:
        mov ax,0x8
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x146
L4DD:
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        jmp short $+41
        nop
        nop
L4EB:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x28
        jmp L150
L503:
        mov ax,0x25
L506:
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
L510:
        add sp,0x4
        jmp LC1
        nop
L517:
        cmp word ptr mn6A02,0x96
        jnz short $+5
        jmp L6E9
L522:
        cmp word ptr mn6A02,0x95
        jnz short $+5
        jmp L6E9
L52D:
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x2
        sub ax,0x122
        jz short $+25
        sub ax,0x24
        jz short $+44
        dec ax
        jnz short $+5
        jmp L5FF
L549:
        sub ax,0x3
        jnz short $+5
        jmp L689
L551:
        jmp LC1
        nop
L555:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x1a
        jmp L150
L56D:
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_10
        add sp,0x4
        or ax,ax
        jnz short $+30
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_10
        add sp,0x4
        or ax,ax
        jnz short $+10
        mov word ptr [bp-0xc],0x6f
        jmp short $+8
        nop
L59D:
        mov word ptr [bp-0xc],0x69
L5A2:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0xc]
        cmp byte ptr mb0343,0x0
        jz short $+7
        mov ax,0x25dc
        jmp short $+5
L5C3:
        mov ax,0x25e3
L5C6:
        push ds
        push ax
        mov ax,0x1c
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0xe
        mov ax,0x122
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        add sp,0x4
        xor ax,ax
        mov mb0343,al
        push ax
        push ax
        mov ax,0x76
        push ax
L5F3:
        call far ptr helper_6
        add sp,0x6
        jmp LC1
        nop
L5FF:
        cmp word ptr mn0256,0x94
        jz short $+104
        cmp word ptr mn0256,0x97
        jz short $+96
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_10
        add sp,0x4
        or ax,ax
        jnz short $+30
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_10
        add sp,0x4
        or ax,ax
        jnz short $+10
        mov word ptr [bp-0xa],0x6f
        jmp short $+8
        nop
L63F:
        mov word ptr [bp-0xa],0x69
L644:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0xa]
        mov ax,0x1b
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0xa
        jmp LC1
        nop
L66D:
        push word ptr mn6A04
        cmp word ptr mn0256,0x97
        jnz short $+8
        mov ax,0x95
        jmp short $+6
        nop
L67F:
        mov ax,0x96
L682:
        push ax
L683:
        mov ax,0xd
        jmp L38
L689:
        mov ax,0x11
        push ax
        push word ptr mn6A02
        call far ptr helper_10
        add sp,0x4
        or ax,ax
        jnz short $+30
        mov ax,0x1
        push ax
        push word ptr mn6A02
        call far ptr helper_10
        add sp,0x4
        or ax,ax
        jnz short $+10
        mov word ptr [bp-0xe],0x6f
        jmp short $+8
        nop
L6B9:
        mov word ptr [bp-0xe],0x69
L6BE:
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        push word ptr [bp-0xe]
        mov ax,0x1d
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0xa
        mov ax,0x122
        jmp L4DD
L6E9:
        call far ptr helper_7
        or ax,ax
        jz short $+5
        jmp L8D3
L6F5:
        push word ptr mn6A02
        mov ax,0x22
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
        mov ax,0x19
        jmp LB4
L71F:
        cmp word ptr mn6A02,0x77
        jnz short $+13
        push word ptr mn6A02
        push word ptr mn6A04
        jmp L35
L731:
        cmp word ptr mn6A02,0x96
        jz short $+34
        cmp word ptr mn6A02,0x95
        jz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x32
        jmp L150
L759:
        push word ptr mn6A04
        push word ptr mn6A02
        jmp L683
        nop
L765:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+26
        push word ptr mn6A04
        mov ax,0x22
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x15
        jmp L150
L791:
        mov ax,0x1
        push ax
        mov ax,0x8b
        push ax
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x16
        jmp L506
L7AB:
        push word ptr mn6A04
        call far ptr helper_11
        add sp,0x2
        push ax
        mov ax,0x22
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
        mov ax,0x17
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0xc
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_11
        add sp,0x2
        push ax
        call far ptr helper_10
        add sp,0x4
        or ax,ax
        jnz short $+43
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_11
        add sp,0x2
        push ax
        call far ptr helper_12
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push ax
        call far ptr helper_13
        add sp,0x6
L82E:
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        push word ptr mn6A04
        jmp L5F3
        nop
L83D:
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jnz short $+26
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x33
        jmp L150
L869:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x34
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        push word ptr mn6A04
        call far ptr helper_1
        add sp,0x2
        cmp ax,0x147
        jnz short $+18
        mov ax,0x35
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_3
        add sp,0x4
L8AC:
        mov ax,0x2e
        push ax
        call far ptr helper_14
        add sp,0x2
        jmp LC1
L8BB:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        add sp,0x4
        push dx
        push ax
        mov ax,0x18
        jmp L150
L8D3:
        xor ax,ax
L8D5:
    }
}
