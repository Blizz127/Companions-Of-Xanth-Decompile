extern int __near mn6A1E;
extern int __near mn5B26;
extern int __near mn02D0;
extern int __near mn02D2;
extern char __near mb5E34;
extern char __near mb030E;
extern char __near mb1D00;
extern char __near mb0341;
extern int __near mn02D4;
extern int __near mn02A8;
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
int far ovl_264339(int a)
{
    _asm {
        sub sp,0x4
        mov byte ptr [bp-0x2],0x20
        cmp word ptr mn6A1E,0x0
        jz short $+40
        cmp word ptr mn6A1E,0x4e
        jz short $+112
        cmp word ptr mn6A1E,0xad
        jz short $+104
        cmp word ptr mn6A1E,0x14e
        jz short $+96
        push word ptr mn6A1E
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x2],al
L34:
        mov es, mn5B26
        mov cl,0x4
        mov bx,mn02D0
        mov ax,bx
        add bx,bx
        add bx,bx
        add bx,ax
        add bx,mn02D2
        shl bx,cl
        mov al,es:[bx+0x5c0]
        mov [bp-0x4],al
        cmp al,0x58
        jnz short $+6
        mov byte ptr [bp-0x4],0x54
L5C:
        mov byte ptr mb5E34,0x0
        call far ptr helper_1
        mov al,[bp-0x2]
        cmp [bp-0x4],al
        jz short $+5
        jmp L136
L71:
        cmp al,0x54
        jz short $+5
        jmp L125
L78:
        mov ax,0x1
        push ax
        push ax
        mov ax,0xa
        jmp L12D
L83:
        cmp word ptr mn6A1E,0x14e
        jz short $+8
        mov byte ptr [bp-0x2],0x54
        jmp short $-91
L91:
        mov ax,0x49
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x355e
        push ds
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x1388
        push ax
        call far ptr helper_4
        add sp,0x2
        mov byte ptr mb030E,0x1
        mov byte ptr mb5E34,0x0
        call far ptr helper_5
        mov ax,0xe19
        push ax
        mov ax,0x37f
        push ax
        call far ptr helper_6
        add sp,0x4
        mov ax,0x4a
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        push ax
        mov cx,0xa
        push cx
        call far ptr helper_7
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov ax,0x14e
        push ax
        call far ptr helper_8
        add sp,0x6
        mov ax,0xfa0
        push ax
        call far ptr helper_4
        mov ax,0x2
        add sp,ax
        push ax
        call far ptr helper_9
L11E:
        add sp,0x2
        jmp L266
        nop
L125:
        mov ax,0x1
        push ax
        push ax
        mov ax,0x3
L12D:
        push ax
        call far ptr helper_7
        add sp,0x6
L136:
        mov ax,0x7d0
        push ax
        call far ptr helper_4
        add sp,0x2
        mov al,[bp-0x2]
        cmp [bp-0x4],al
        jz short $+5
        jmp L231
L14D:
        cmp al,0x54
        jnz short $+18
        xor ax,ax
        push ax
        push ax
        push word ptr mn6A1E
        call far ptr helper_8
        add sp,0x6
L161:
        mov byte ptr mb1D00,0x0
        mov ax,0xe19
        push ax
        mov ax,0x375
        push ax
        call far ptr helper_6
        add sp,0x4
        inc word ptr mn02D2
        cmp word ptr mn02D2,0x5
        jl short $+50
        mov ax,mn02D0
        dec ax
        jz short $+8
        dec ax
        jz short $+51
        jmp L266
L18D:
        mov byte ptr mb1D00,0x0
        mov ax,0xe19
        push ax
        mov cx,0x377
        push cx
        call far ptr helper_6
        add sp,0x4
        inc word ptr mn02D0
        mov word ptr mn02D2,0x0
        call far ptr helper_10
L1B1:
        mov ax,0xe19
        push ax
        mov ax,0x374
        jmp L260
L1BB:
        xor ax,ax
        push ax
        push ax
        mov cx,0x149
        push cx
        call far ptr helper_8
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0x14a
        push cx
        call far ptr helper_8
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0x14b
        push cx
        call far ptr helper_8
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov cx,0x14c
        push cx
        call far ptr helper_8
        add sp,0x6
        xor ax,ax
        push ax
        push ax
        mov ax,0x14d
        push ax
        call far ptr helper_8
        add sp,0x6
        mov byte ptr mb1D00,0x0
        mov ax,0xe19
        push ax
        mov ax,0x37a
        push ax
        call far ptr helper_6
        add sp,0x4
        mov byte ptr mb0341,0x1
L225:
        mov ax,0x5a
        push ax
        call far ptr helper_11
        jmp L11E
L231:
        inc word ptr mn02D4
        cmp word ptr mn02D4,0x3
        jnz short $+31
        mov byte ptr mb1D00,0x0
        mov ax,0xe19
        push ax
        mov ax,0x387
        push ax
        call far ptr helper_6
        add sp,0x4
        mov word ptr mn02A8,0x19
        jmp short $-50
L259:
        mov ax,0xe19
        push ax
        mov ax,0x376
L260:
        push ax
        call far ptr helper_6
L266:
        mov ax,0x1
    }
}
