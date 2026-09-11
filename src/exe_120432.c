extern int __near mn51DE;
extern int __near mn51E0;
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
int far exe_120432(int a)
{
    _asm {
        sub sp,0x10
        cmp word ptr mn51DE,0x1
        jnl short lbl0Ff
        xor ax,ax
        jmp lbl23Ef
lbl0Ff:
lbl0Fb:
        cmp word ptr mn51E0,0x0
        jnl short lbl1Df
        mov ax,mn51DE
        dec ax
        mov mn51E0,ax
lbl1Df:
lbl1Db:
        mov ax,0xd
        push ax
        xor ax,ax
        mov [bp-0xc],ax
        push ax
        push ax
        push word ptr mn51E0
        call far ptr helper_0
        add sp,0x8
        call far ptr helper_1
        mov [bp-0xa],ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_2
        add sp,0x4
        call far ptr helper_3
        mov ax,0x1
        push ax
        call far ptr helper_4
        add sp,0x2
        mov [bp-0x8],ax
        call far ptr helper_5
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x10],ax
        mov [bp-0xe],dx
        mov es,dx
        mov bx,ax
        cmp byte ptr es:[bx],0x0
        jnz short lbl7Cf
        jmp lbl17Cf
lbl7Cf:
lbl7Cb:
        inc word ptr [bp-0x10]
        mov bx,[bp-0x10]
        cmp byte ptr es:[bx],0x0
        jnz short lbl7Cb
        jmp lbl17Cf
lbl8Bf:
lbl8Bb:
        call far ptr helper_6
        or ax,ax
        jnz short lbl97f
        jmp lbl17Cf
lbl97f:
lbl97b:
        call far ptr helper_7
        mov [bp-0x6],ax
        cmp ax,0x1b
        jnz short lblA7f
        jmp lbl19Df
lblA7f:
lblA7b:
        ja short lblBBf
        sub al,0x3
        jnz short lblB0f
        jmp lbl19Df
lblB0f:
lblB0b:
        sub al,0x5
        jz short lblFFf
        sub al,0x5
        jnz short lblBBf
        jmp lbl219f
lblBBf:
lblBBb:
        cmp word ptr [bp-0x6],0x20
        jnl short lblC4f
        jmp lbl17Cf
lblC4f:
lblC4b:
        cmp word ptr [bp-0x6],0x7f
        jl short lblCDf
        jmp lbl17Cf
lblCDf:
lblCDb:
        mov ax,[bp-0x10]
        sub ax,[bp+0x6]
        mov cx,[bp+0xa]
        dec cx
        cmp ax,cx
        jl short lblDEf
        jmp lbl17Cf
lblDEf:
lblDEb:
        mov al,[bp-0x6]
        les bx, [bp-0x10]
        mov es:[bx],al
        inc word ptr [bp-0x10]
        les bx, [bp-0x10]
        mov byte ptr es:[bx],0x0
        push word ptr [bp-0x6]
        call far ptr helper_8
        add sp,0x2
        jmp short lbl17Cf
        nop
lblFFf:
lblFFb:
        mov ax,[bp+0x6]
        cmp [bp-0x10],ax
        jna short lbl17Cf
        dec word ptr [bp-0x10]
        les bx, [bp-0x10]
        mov byte ptr es:[bx],0x0
        lea ax,[bp-0x4]
        push ss
        push ax
        lea cx,[bp-0x2]
        push ss
        push cx
        push word ptr mn51E0
        call far ptr helper_9
        add sp,0xa
        sub word ptr [bp-0x2],0x8
        call far ptr helper_3
        xor ax,ax
        push ax
        call far ptr helper_4
        add sp,0x2
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        push word ptr mn51E0
        call far ptr helper_10
        add sp,0x6
        mov ax,0x20
        push ax
        call far ptr helper_8
        add sp,0x2
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        push word ptr mn51E0
        call far ptr helper_10
        add sp,0x6
        mov ax,0x1
        push ax
        call far ptr helper_4
        add sp,0x2
        call far ptr helper_5
lbl17Cf:
lbl17Cb:
        call far ptr helper_11
        or ax,ax
        jnz short lbl188f
        jmp lbl8Bb
lbl188f:
lbl188b:
        mov ax,[bp+0x6]
        cmp [bp-0x10],ax
        jna short lbl195f
        mov ax,0x1
        jmp short lbl197f
lbl195f:
lbl195b:
        xor ax,ax
lbl197f:
lbl197b:
        mov [bp-0xc],ax
        jmp lbl21Ef
lbl19Df:
lbl19Db:
        call far ptr helper_3
        xor ax,ax
        push ax
        call far ptr helper_4
        add sp,0x2
        mov ax,[bp+0x6]
        cmp [bp-0x10],ax
        jna short lbl211f
lbl1B5f:
lbl1B5b:
        dec word ptr [bp-0x10]
        les bx, [bp-0x10]
        mov byte ptr es:[bx],0x0
        lea ax,[bp-0x4]
        push ss
        push ax
        lea cx,[bp-0x2]
        push ss
        push cx
        push word ptr mn51E0
        call far ptr helper_9
        add sp,0xa
        push word ptr [bp-0x4]
        sub word ptr [bp-0x2],0x8
        push word ptr [bp-0x2]
        push word ptr mn51E0
        call far ptr helper_10
        add sp,0x6
        mov ax,0x20
        push ax
        call far ptr helper_8
        add sp,0x2
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        push word ptr mn51E0
        call far ptr helper_10
        add sp,0x6
        mov ax,[bp+0x6]
        cmp [bp-0x10],ax
        ja short lbl1B5b
lbl211f:
lbl211b:
        call far ptr helper_5
        jmp short lbl21Ef
        nop
lbl219f:
lbl219b:
        mov word ptr [bp-0xc],0x1
lbl21Ef:
lbl21Eb:
        call far ptr helper_3
        push word ptr [bp-0x8]
        call far ptr helper_4
        add sp,0x2
        call far ptr helper_5
        push word ptr [bp-0xa]
        call far ptr helper_12
        mov ax,[bp-0xc]
lbl23Ef:
lbl23Eb:
    }
}
