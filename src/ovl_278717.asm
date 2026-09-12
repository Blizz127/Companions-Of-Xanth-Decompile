_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi12:NEAR
    EXTRN mf21:FAR
    EXTRN mf29:FAR
    EXTRN mf38:FAR
    EXTRN mf45:FAR
    EXTRN mf55:FAR
    EXTRN mf63:FAR
    EXTRN mi69:NEAR
    EXTRN mf86:FAR
    EXTRN mf93:FAR
    EXTRN mf100:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl16f
    dec ax
    dec ax
    jnz short lbl12f
    jmp near ptr lblACf
lbl12f:
    jmp near ptr lbl102f
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl102f
lbl21f:
    cmp word ptr ds:[6A04h],16Dh
    jnz short lbl3Af
    mov ax,12h
    mov dx,0F03Eh
    push dx
    push ax
    call mf21
    mov sp,bp
    jmp short lblA6f
lbl3Af:
    cmp word ptr ds:[6A04h],168h
    jnz short lbl58f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf29
    mov sp,bp
    push dx
    push ax
    mov ax,13h
    jmp short lbl99f
lbl58f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf38
    add sp,4h
    or ax,ax
    jnz short lbl84f
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf45
    add sp,4h
    push dx
    push ax
    mov ax,14h
    jmp short lbl99f
    nop
lbl84f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf55
    add sp,4h
    push dx
    push ax
    mov ax,15h
lbl99f:
    mov dx,0F03Eh
    push dx
    push ax
    call mf63
    add sp,8h
lblA6b:
lblA6f:
    mov ax,1h
    jmp short lbl104f
    nop
lblACf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi69
    jz short lblF6f
    ja short lbl102f
    cmp al,2Ch
    jz short lblD0f
    ja short lblC6f
    sub al,8h
    jz short lblD0f
    sub al,0Bh
    jz short lblDEf
    jmp short lbl102f
lblC6f:
    sub al,38h
    jz short lblF0f
    sub al,0Ch
    jz short lblF0f
    jmp short lbl102f
lblD0f:
    push word ptr ds:[6A04h]
    call mf86
lblD9b:
    add sp,2h
    jmp short lblA6b
lblDEf:
    mov ax,10h
lblE1b:
    mov dx,0F03Eh
    push dx
    push ax
    call mf93
    add sp,4h
    jmp short lblA6b
lblF0f:
    mov ax,11h
    jmp short lblE1b
    nop
lblF6f:
    push word ptr ds:[6A04h]
    call mf100
    jmp short lblD9b
    nop
lbl102f:
    xor ax,ax
lbl104f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
