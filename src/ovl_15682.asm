_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf1e9:FAR
    EXTRN mf162:FAR
    EXTRN mf47:FAR
    EXTRN mf1cb:FAR
    EXTRN mf9c:FAR
    EXTRN mfc3:FAR
    EXTRN mfe1:FAR
    EXTRN mf175:FAR
    EXTRN mf1e4:FAR
    EXTRN mf89:FAR
    EXTRN mf64:FAR
    EXTRN mf13a:FAR
    EXTRN mf192:FAR
    EXTRN mf1b7:FAR
    EXTRN mf112:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8Ch
    push di
    push si
    sub ax,ax
    mov word ptr [bp-4h],ax
    mov word ptr [bp-6h],ax
    cmp word ptr [bp+6h],2h
    jnz short lbl1Af
    jmp near ptr lblBCf
lbl1Af:
    cmp word ptr [bp+6h],1h
    jnz short lbl23f
    jmp near ptr lblBCf
lbl23f:
    cmp word ptr [bp+6h],4h
    jnz short lbl2Cf
    jmp near ptr lblBCf
lbl2Cf:
    cmp word ptr [bp+6h],3h
    jz short lbl35f
    jmp near ptr lblB6f
lbl35f:
    mov byte ptr ds:[18A3h],al
    cmp byte ptr ds:[18A2h],al
    jz short lbl47f
    mov ax,word ptr ds:[189Eh]
    or ax,word ptr ds:[189Ch]
    jnz short lbl5Cf
lbl47f:
    call mf47
    cmp byte ptr ds:[18A2h],0h
    jz short lblB6f
    mov ax,word ptr ds:[189Eh]
    or ax,word ptr ds:[189Ch]
    jz short lblB6f
lbl5Cf:
    push word ptr ds:[189Eh]
    push word ptr ds:[189Ch]
    call mf64
    add sp,4h
    les bx, dword ptr ds:[189Ch]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-8Ah],ax
    mov word ptr [bp-88h],dx
    lea ax,word ptr [bp-8Ah]
    push ss
    push ax
    mov ax,3h
    push ax
    call mf89
    add sp,6h
    mov word ptr [bp-2h],ax
    push word ptr ds:[189Eh]
    push word ptr ds:[189Ch]
    call mf9c
    add sp,4h
    cmp word ptr [bp-2h],0h
    jz short lblADf
    jmp near ptr lbl19Df
lblADf:
    mov byte ptr ds:[18A3h],1h
    jmp near ptr lbl19Df
    nop
lblB6f:
    mov ax,0FFFFh
    jmp near ptr lbl1F1f
lblBCf:
    cmp word ptr [bp+6h],2h
    jnz short lbl11Cf
    push ax
    call mfc3
    add sp,2h
    mov word ptr [bp-8Ch],ax
    or ax,ax
    jnl short lblDCf
lblD3b:
    mov word ptr [bp-2h],0FFFFh
    jmp near ptr lbl19Df
    nop
lblDCf:
    push ax
    mov ax,5h
    push ax
    call mfe1
    add sp,4h
    mov di,ax
    lea si,word ptr [bp-86h]
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
    lea ax,word ptr [bp-86h]
    push ss
    push ax
    call mf112
    add sp,4h
    jmp short lbl16Af
lbl11Cf:
    cmp word ptr [bp+6h],4h
    jnz short lbl14Af
    mov ax,1884h
    push ds
    push ax
    mov ax,48h
    mov cx,2EC4h
    push cx
    push ax
    mov ax,18D0h
    push ds
    push ax
    lea ax,word ptr [bp-86h]
    push ss
    push ax
    call mf13a
    add sp,10h
    mov word ptr [bp+6h],2h
    jmp short lbl16Af
    nop
lbl14Af:
    mov ax,188Eh
    push ds
    push ax
    mov ax,48h
    mov cx,2EC4h
    push cx
    push ax
    mov ax,18D6h
    push ds
    push ax
    lea ax,word ptr [bp-86h]
    push ss
    push ax
    call mf162
    add sp,10h
lbl16Af:
    mov ax,18DCh
    push ds
    push ax
    lea ax,word ptr [bp-86h]
    push ss
    push ax
    call mf175
    add sp,8h
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    or dx,ax
    jnz short lbl18Af
    jmp near ptr lblD3b
lbl18Af:
    push word ptr [bp-4h]
    push ax
    mov ax,2h
    push ax
    call mf192
    add sp,6h
    mov word ptr [bp-2h],ax
lbl19Df:
    cmp word ptr [bp+6h],2h
    jz short lbl1A9f
    cmp word ptr [bp+6h],1h
    jnz short lbl1D3f
lbl1A9f:
    mov ax,word ptr [bp-4h]
    or ax,word ptr [bp-6h]
    jz short lbl1BFf
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf1b7
    add sp,4h
lbl1BFf:
    cmp word ptr [bp-2h],0h
    jnl short lbl1D3f
    lea ax,word ptr [bp-86h]
    push ss
    push ax
    call mf1cb
    add sp,4h
lbl1D3f:
    cmp word ptr [bp+6h],3h
    jz short lbl1DEf
    mov byte ptr ds:[18A3h],0h
lbl1DEf:
    cmp word ptr [bp+6h],2h
    jnz short lbl1EEf
    call mf1e4
    call mf1e9
lbl1EEf:
    mov ax,word ptr [bp-2h]
lbl1F1f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
