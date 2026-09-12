_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi12:NEAR
    EXTRN mf28:FAR
    EXTRN mi33:NEAR
    EXTRN mf46:FAR
    EXTRN mi65:NEAR
    EXTRN mf69:FAR
    EXTRN mf73:FAR
    EXTRN mf80:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    sub word ptr [bp+8h],0Ch
    cmp word ptr [bp+8h],0h
    jl short lbl16f
    jmp near ptr lbl1Bf
lbl16f:
    mov word ptr [bp+8h],0h
lbl1Bf:
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi12
    jz short lbl27f
    jmp near ptr lbl30f
lbl27f:
    cmp word ptr [bp+6h],9h
    jnc short lbl30f
    jmp near ptr lbl39f
lbl30f:
    cmp word ptr [bp+6h],6h
    jc short lbl39f
    jmp near ptr lbl5Af
lbl39f:
    mov ax,word ptr [bp+8h]
    mov bx,word ptr [bp+6h]
    mov byte ptr [bx+5E3Ah],al
    mov bx,word ptr [bp+6h]
    mov byte ptr [bx+5E44h],20h
    mov ax,word ptr [bp+6h]
    push ax
    call mf28
    add sp,2h
    jmp near ptr lblE7f
lbl5Af:
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi33
    jnz short lbl66f
    jmp near ptr lblE7f
lbl66f:
    cmp word ptr [bp+6h],0Ah
    jna short lbl6Ff
    jmp near ptr lblE7f
lbl6Ff:
    cmp word ptr [bp+6h],6h
    jz short lbl78f
    jmp near ptr lbl8Df
lbl78f:
    mov ax,word ptr [bp+8h]
    mov byte ptr ds:[5E40h],al
    mov ax,word ptr [bp+6h]
    push ax
    call mf46
    add sp,2h
    jmp near ptr lblD3f
lbl8Df:
    cmp word ptr [bp+6h],8h
    jz short lbl96f
    jmp near ptr lblD3f
lbl96f:
    mov al,byte ptr ds:[5E42h]
    cbw
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp+8h]
    cbw
    mov cx,word ptr [bp-4h]
    cmp cx,ax
    jnz short lblABf
    jmp near ptr lblD3f
lblABf:
    mov ax,word ptr [bp+8h]
    mov byte ptr ds:[5E42h],al
    mov ax,word ptr [bp+8h]
    cbw
    add ax, offset mi65
    mov byte ptr ds:[5E41h],al
    mov ax,8h
    push ax
    call mf69
    add sp,2h
    mov ax,7h
    push ax
    call mf73
    add sp,2h
lblD3f:
    mov bx,word ptr [bp+6h]
    add bx,0FFFFFFFFFFFFFFFAh
    mov al,byte ptr [bx+3FF0h]
    cbw
    or byte ptr ds:[5E38h],al
    call mf80
lblE7f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
