_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf32:FAR
    EXTRN mf44:FAR
    EXTRN mf58:FAR
    EXTRN mf66:FAR
    EXTRN mf86:FAR
    EXTRN mf97:FAR
    EXTRN mf105:FAR
    EXTRN mf111:FAR
    EXTRN mf156:FAR
    EXTRN mf156:FAR
    EXTRN mf156:FAR
    EXTRN mf156:FAR
    EXTRN mf156:FAR
    EXTRN mf156:FAR
    EXTRN mf156:FAR
    EXTRN mf156:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2Ah
    push di
    push si
    xor ax,ax
    mov cx,8h
    lea di,word ptr [bp-1Ah]
    push ss
    pop es
    rep stosw
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],ax
    mov cx,word ptr ds:[5B02h]
    dec cx
    cmp cx,ax
    ja short lbl26f
    jmp near ptr lbl16Bf
lbl26f:
    mov ax,word ptr ds:[5B00h]
    dec ax
    mov word ptr [bp-26h],ax
lbl2Db:
    mov word ptr [bp-6h],0h
    cmp word ptr [bp-26h],0h
    jnz short lbl3Bf
    jmp near ptr lbl15Bf
lbl3Bb:
lbl3Bf:
    mov word ptr [bp-4h],1h
lbl40b:
    push word ptr [bp-8h]
    mov ax,word ptr [bp-6h]
    add ax,word ptr [bp-4h]
    mov word ptr [bp-28h],ax
    dec ax
    push ax
    call mf32
    add sp,4h
    or ax,ax
    jnz short lbl5Df
    jmp near ptr lbl14Df
lbl5Df:
    mov ax,word ptr [bp-4h]
    add ax,ax
    add ax,word ptr [bp-8h]
    mov word ptr [bp-2Ah],ax
    dec ax
    push ax
    push word ptr [bp-6h]
    call mf44
    add sp,4h
    or ax,ax
    jnz short lbl7Cf
    jmp near ptr lbl14Df
lbl7Cf:
    mov word ptr [bp-2h],0h
    cmp word ptr [bp-4h],0h
    jz short lblC1f
lbl87b:
    mov ax,word ptr [bp-2h]
    add ax,ax
    add ax,word ptr [bp-8h]
    inc ax
    push ax
    push word ptr [bp-28h]
    call mf58
    add sp,4h
    or ax,ax
    jz short lblC1f
    push word ptr [bp-2Ah]
    mov ax,word ptr [bp-6h]
    add ax,word ptr [bp-2h]
    push ax
    call mf66
    add sp,4h
    or ax,ax
    jz short lblC1f
    mov ax,word ptr [bp-4h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl87b
lblC1f:
    mov ax,word ptr [bp-2h]
    cmp word ptr [bp-4h],ax
    ja short lbl141f
    inc word ptr [bp-0Ah]
    mov word ptr [bp-2h],0h
    cmp word ptr [bp-4h],0h
    jz short lbl141f
lblD7b:
    push word ptr [bp-8h]
    mov ax,word ptr [bp-6h]
    add ax,word ptr [bp-2h]
    push ax
    mov si,ax
    call mf86
    add sp,4h
    mov di,ax
    mov byte ptr [bp+di-1Bh],1h
    mov ax,word ptr [bp-2h]
    add ax,ax
    add ax,word ptr [bp-8h]
    inc ax
    push ax
    push word ptr [bp-6h]
    mov di,ax
    call mf97
    add sp,4h
    mov cx,si
    mov si,ax
    mov byte ptr [bp+si-1Bh],1h
    push di
    push word ptr [bp-28h]
    mov si,cx
    call mf105
    add sp,4h
    mov di,ax
    mov byte ptr [bp+di-1Bh],1h
    push word ptr [bp-2Ah]
    push si
    call mf111
    add sp,4h
    mov si,ax
    mov byte ptr [bp+si-1Bh],1h
    mov ax,word ptr [bp-4h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lblD7b
lbl141f:
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],6h
    jnc short lbl14Df
    jmp near ptr lbl40b
lbl14Df:
    inc word ptr [bp-6h]
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-26h],ax
    jna short lbl15Bf
    jmp near ptr lbl3Bb
lbl15Bf:
    mov ax,word ptr ds:[5B02h]
    dec ax
    add word ptr [bp-8h],2h
    cmp ax,word ptr [bp-8h]
    jna short lbl16Bf
    jmp near ptr lbl2Db
lbl16Bf:
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[5E0Ah],0h
    jz short lbl19Af
    lea ax,word ptr [bp-1Ah]
    mov word ptr [bp-24h],ax
lbl17Db:
    mov bx,word ptr [bp-24h]
    cmp byte ptr [bx],0h
    jz short lbl196f
    inc word ptr [bp-24h]
    mov ax,word ptr ds:[5E0Ah]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl17Db
    jmp short lbl19Af
    nop
lbl196f:
    xor ax,ax
    jmp short lbl19Df
lbl19Af:
    mov ax,word ptr [bp-0Ah]
lbl19Df:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
