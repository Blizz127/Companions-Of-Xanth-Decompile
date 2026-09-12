_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi12:NEAR
    EXTRN mf20:FAR
    EXTRN mf27:FAR
    EXTRN mf37:FAR
    EXTRN mf43:FAR
    EXTRN mf49:FAR
    EXTRN mf56:FAR
    EXTRN mf64:FAR
    EXTRN mi70:NEAR
    EXTRN mf92:FAR
    EXTRN mf92:FAR
    EXTRN mf92:FAR
    EXTRN mf92:FAR
    EXTRN mf92:FAR
    EXTRN mf92:FAR
    EXTRN mf92:FAR
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
    jmp near ptr lblD6f
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lblD6f
lbl21f:
    cmp word ptr ds:[6A04h],1EEh
    jnz short lbl74f
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf20
    mov sp,bp
    or ax,ax
    jnz short lbl52f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf27
    mov sp,bp
    push dx
    push ax
    mov ax,2Bh
    jmp short lbl9Af
lbl52f:
    mov ax,2Ch
    mov dx,0F04Ch
    push dx
    push ax
    call mf37
    mov sp,bp
    xor ax,ax
    push ax
    push word ptr ds:[256h]
    push word ptr ds:[6A04h]
    call mf43
    jmp short lblA4f
    nop
lbl74f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf49
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf56
    add sp,4h
    push dx
    push ax
    mov ax,2Dh
lbl9Ab:
lbl9Af:
    mov dx,0F04Ch
    push dx
    push ax
    call mf64
lblA4f:
    mov sp,bp
    mov ax,1h
    jmp short lblD8f
    nop
lblACf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi70
    jz short lblD0f
    ja short lblD6f
    sub al,13h
    jz short lblC4f
    sub al,19h
    jz short lblC4f
    sub al,18h
    jz short lblCAf
    jmp short lblD6f
lblC4f:
    mov ax,28h
    jmp short lbl9Ab
    nop
lblCAf:
    mov ax,29h
    jmp short lbl9Ab
    nop
lblD0f:
    mov ax,2Ah
    jmp short lbl9Ab
    nop
lblD6f:
    xor ax,ax
lblD8f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
