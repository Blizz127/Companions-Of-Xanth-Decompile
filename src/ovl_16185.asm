_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf56:FAR
    EXTRN mf18:FAR
    EXTRN mf14b:FAR
    EXTRN mf113:FAR
    EXTRN mf207:FAR
    EXTRN mf1d4:FAR
    EXTRN mfec:FAR
    EXTRN mf16a:FAR
    EXTRN mf182:FAR
    EXTRN mf1ef:FAR
    EXTRN mf8b:FAR
    EXTRN mf1ba:FAR
    EXTRN mfbd:FAR
    EXTRN mf1a7:FAR
    EXTRN mf78:FAR
    EXTRN mf1c2:FAR
    EXTRN mf139:FAR
    EXTRN mfa0:FAR
    EXTRN mf217:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4Eh
    push di
    push si
    sub ax,ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-8h],ax
    mov ax,34h
    mov cx,2199h
    push cx
    push ax
    call mf18
    add sp,4h
    mov ax,word ptr ds:[256h]
    mov word ptr [bp-4h],ax
    cmp word ptr [bp+6h],2h
    jz short lbl96f
    cmp word ptr [bp+6h],1h
    jz short lbl96f
    cmp word ptr [bp+6h],4h
    jz short lbl96f
    cmp word ptr [bp+6h],3h
    jnz short lbl47f
    mov ax,word ptr ds:[189Eh]
    or ax,word ptr ds:[189Ch]
    jnz short lbl4Ef
lbl47f:
    mov ax,0FFFFh
    jmp near ptr lbl227f
    nop
lbl4Ef:
    push word ptr ds:[189Eh]
    push word ptr ds:[189Ch]
    call mf56
    add sp,4h
    les bx, dword ptr ds:[189Ch]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-4Ch],ax
    mov word ptr [bp-4Ah],dx
    lea ax,word ptr [bp-4Ch]
    push ss
    push ax
    mov ax,0Bh
    push ax
    call mf78
    add sp,6h
    mov word ptr [bp-2h],ax
    push word ptr ds:[189Eh]
    push word ptr ds:[189Ch]
    call mf8b
    add sp,4h
    jmp near ptr lbl18Df
lbl96f:
    cmp word ptr [bp+6h],2h
    jnz short lblF6f
    mov ax,1h
    push ax
    call mfa0
    add sp,2h
    mov word ptr [bp-4Eh],ax
    or ax,ax
    jnl short lblB8f
    mov word ptr [bp-2h],1h
    jmp near ptr lbl18Df
    nop
lblB8f:
    push ax
    mov ax,4h
    push ax
    call mfbd
    add sp,4h
    mov di,ax
    lea si,word ptr [bp-48h]
    mov es,dx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    lea ax,word ptr [bp-48h]
    push ss
    push ax
    call mfec
    add sp,4h
    jmp short lbl141f
lblF6f:
    cmp word ptr [bp+6h],4h
    jnz short lbl122f
    mov ax,1884h
    push ds
    push ax
    mov ax,48h
    mov cx,2EC4h
    push cx
    push ax
    mov ax,18DFh
    push ds
    push ax
    lea ax,word ptr [bp-48h]
    push ss
    push ax
    call mf113
    add sp,10h
    mov word ptr [bp+6h],2h
    jmp short lbl141f
lbl122f:
    mov ax,188Eh
    push ds
    push ax
    mov ax,48h
    mov cx,2EC4h
    push cx
    push ax
    mov ax,18E5h
    push ds
    push ax
    lea ax,word ptr [bp-48h]
    push ss
    push ax
    call mf139
    add sp,10h
lbl141f:
    mov ax,18EBh
    push ds
    push ax
    lea ax,word ptr [bp-48h]
    push ss
    push ax
    call mf14b
    add sp,8h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    or dx,ax
    jnz short lbl17Af
    lea ax,word ptr [bp-48h]
    push ss
    push ax
    mov ax,12h
    mov cx,3153h
    push cx
    push ax
    call mf16a
    add sp,8h
    mov word ptr [bp-2h],0FFFFh
    jmp short lbl18Df
    nop
lbl17Af:
    push word ptr [bp-6h]
    push ax
    mov ax,0Ah
    push ax
    call mf182
    add sp,6h
    mov word ptr [bp-2h],ax
lbl18Df:
    cmp word ptr [bp+6h],2h
    jz short lbl199f
    cmp word ptr [bp+6h],1h
    jnz short lbl1C2f
lbl199f:
    mov ax,word ptr [bp-6h]
    or ax,word ptr [bp-8h]
    jz short lbl1AFf
    push word ptr [bp-6h]
    push word ptr [bp-8h]
    call mf1a7
    add sp,4h
lbl1AFf:
    cmp word ptr [bp-2h],0h
    jnl short lbl1C2f
    lea ax,word ptr [bp-48h]
    push ss
    push ax
    call mf1ba
    add sp,4h
lbl1C2f:
    call mf1c2
    cmp word ptr [bp-2h],0h
    jnz short lbl224f
    mov ax,18h
    push ax
    push word ptr [bp-4h]
    call mf1d4
    add sp,4h
    cmp word ptr [bp+6h],3h
    jnz short lbl1E7f
    mov byte ptr ds:[18A3h],0h
lbl1E7f:
    mov ax,19h
    push ax
    push word ptr ds:[256h]
    call mf1ef
    add sp,4h
    mov byte ptr ds:[189Ah],0h
    push word ptr [bp+6h]
    mov ax,0h
    mov cx,3420h
    push cx
    push ax
    call mf207
    add sp,6h
    mov ax,25h
    mov cx,3153h
    push cx
    push ax
    call mf217
    add sp,4h
    mov word ptr [bp-2h],0FFFFh
lbl224f:
    mov ax,word ptr [bp-2h]
lbl227f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
