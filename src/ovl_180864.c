extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
extern int __near mn02EE;
extern int __near mn02F0;
extern char __near mb029C;
extern int __near mn5AD4;
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
int far ovl_180864(int a)
{
    _asm {
        sub sp,0x12
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+76
        jmp L389
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp L389
L1E:
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
        mov ax,0xd
L45:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0xc
L52:
        mov ax,0x1
        jmp L38B
        nop
L59:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L363
L64:
        jna short $+5
        jmp L389
L69:
        cmp al,0x17
        jnz short $+5
        jmp L125
L70:
        ja short $+13
        sub al,0x8
        jz short $+23
        sub al,0xb
        jz short $+61
        jmp L389
L7D:
        sub al,0x2c
        jz short $+12
        sub al,0x18
        jnz short $+5
        jmp L34B
L88:
        jmp L389
L8B:
        cmp word ptr mn6A06,0x8
        jnz short $+9
        mov ax,0x2f5c
        mov dx,ds
        jmp short $+5
L99:
        xor ax,ax
        cwd
L9C:
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3
        jmp short $-110
LB5:
        mov ax,0x12
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+38
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        xor ax,ax
LDD:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp L52
LED:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2f54
        jmp short $+6
        nop
L107:
        mov ax,0x2f57
L10A:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x1
        jmp L45
        nop
L125:
        cmp word ptr mn02EE,0x10
        jnz short $+111
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x5
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x12
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        call far ptr helper_4
        mov ax,0x17
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        xor ax,ax
        push ax
        push word ptr mn6A04
        call far ptr helper_6
        add sp,0x4
        inc word ptr mn02F0
        cmp word ptr mn02F0,0x10
        jz short $+5
        jmp L52
L190:
        mov byte ptr mb029C,0x1
        jmp L52
        nop
L199:
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L2A1
L1B0:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x6
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_7
        add sp,0x4
        xor ax,ax
        mov [bp-0x6],ax
        mov [bp-0x2],ax
        mov word ptr [bp-0xc],0x5e4
L1EF:
        mov ax,mn6A04
        mov es, mn5AD4
        mov bx,[bp-0xc]
        cmp es:[bx],ax
        jz short $+19
        inc word ptr [bp-0x2]
        add word ptr [bp-0xc],0x2
        cmp word ptr [bp-0xc],0x604
        jc short $-27
        jmp short $+108
        nop
L20F:
        mov ax,[bp-0x2]
        inc ax
        cmp ax,0x10
        jnc short $+92
        add ax,ax
        add ax,0x5e4
        mov [bp-0xe],ax
L220:
        mov ax,0xcd
        push ax
        mov bx,[bp-0xe]
        mov es, mn5AD4
        mov [bp-0x12],bx
        mov word ptr [bp-0x10],es
        push word ptr es:[bx]
        call far ptr helper_8
        add sp,0x4
        or ax,ax
        jz short $+41
        inc word ptr [bp-0x6]
        xor ax,ax
        push ax
        push ax
        les bx, [bp-0x12]
        push word ptr es:[bx]
        call far ptr helper_9
        add sp,0x6
        mov ax,0xa
        push ax
        les bx, [bp-0x12]
        push word ptr es:[bx]
        call far ptr helper_7
        add sp,0x4
L267:
        add word ptr [bp-0xe],0x2
        cmp word ptr [bp-0xe],0x604
        jc short $-80
L272:
        mov ax,[bp-0x2]
        mov mn02EE,ax
L278:
        mov ax,[bp-0x6]
        dec ax
        jz short $+11
        dec ax
        jz short $+14
        mov ax,0x9
        jmp short $+12
        nop
L287:
        mov ax,0x7
        jmp short $+6
        nop
L28D:
        mov ax,0x8
L290:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp L52
        nop
L2A1:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2f73
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0xa
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        inc word ptr mn02EE
        cmp word ptr mn02EE,0x10
        jnz short $+8
        mov ax,0xa
        jmp short $+90
        nop
L2E1:
        mov ax,0xa
        push ax
        mov es, mn5AD4
        mov bx,mn02EE
        add bx,bx
        push word ptr es:[bx+0x5e4]
        call far ptr helper_7
        add sp,0x4
        mov ax,0x12
        push ax
        mov es, mn5AD4
        mov bx,mn02EE
        add bx,bx
        push word ptr es:[bx+0x5e4]
        call far ptr helper_7
        add sp,0x4
        xor ax,ax
        push ax
        push word ptr mn0256
        mov es, mn5AD4
        mov bx,mn02EE
        add bx,bx
        push word ptr es:[bx+0x5e4]
        call far ptr helper_9
        add sp,0x6
        mov ax,0xb
L338:
        mov dx,0xf033
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0xc
        jmp L290
L34B:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2
        jmp LDD
L363:
        mov ax,0x12
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x2f66
        jmp short $+6
        nop
L37D:
        mov ax,0x2f6c
L380:
        push ds
        push ax
        mov ax,0x4
        jmp LDD
        nop
L389:
        xor ax,ax
L38B:
    }
}
