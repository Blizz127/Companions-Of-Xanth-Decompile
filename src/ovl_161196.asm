_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi12:NEAR
    EXTRN mi14:NEAR
    EXTRN mi18:NEAR
    EXTRN mf25:FAR
    EXTRN mf32:FAR
    EXTRN mf40:FAR
    EXTRN mf47:FAR
    EXTRN mf54:FAR
    EXTRN mf62:FAR
    EXTRN mf69:FAR
    EXTRN mi75:NEAR
    EXTRN mi77:NEAR
    EXTRN mf85:FAR
    EXTRN mf91:FAR
    EXTRN mf99:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
    EXTRN mf110:FAR
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
    jmp near ptr lblFCf
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl26f
    sub ax, offset mi14
    jz short lbl26f
    jmp near ptr lblFCf
lbl26f:
    mov ax,word ptr ds:[6A04h]
    sub ax, offset mi18
    jz short lbl66f
    sub ax,156h
    jz short lbl76f
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf25
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf32
    add sp,4h
    push dx
    push ax
    mov ax,32h
    mov dx,0F006h
    push dx
    push ax
    call mf40
    jmp short lblA4f
    nop
lbl66f:
    mov ax,5A13h
    push ax
    mov ax,3E1h
    push ax
    call mf47
    jmp short lblA4f
    nop
lbl76f:
    mov ax,5A13h
    push ax
    mov ax,3DDh
    push ax
    call mf54
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,8h
    push cx
    mov cx,15Fh
    push cx
    call mf62
    mov sp,bp
    xor ax,ax
    push ax
    push ax
    mov ax,14h
    push ax
    call mf69
lblA4f:
    mov sp,bp
lblA6b:
    mov ax,1h
    jmp short lblFEf
    nop
lblACf:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi75
    jz short lblBCf
    sub ax, offset mi77
    jz short lblCCf
    jmp short lblFCf
    nop
lblBCf:
    mov ax,31h
    mov dx,0F006h
    push dx
    push ax
    call mf85
    jmp short lblEDf
    nop
lblCCf:
    push word ptr ds:[6A04h]
    mov ax,15Fh
    push ax
    call mf91
    add sp,4h
    or ax,ax
    jnz short lblF2f
    mov ax,5A13h
    push ax
    mov ax,3DAh
lblE7b:
    push ax
    call mf99
lblEDf:
    add sp,4h
    jmp short lblA6b
lblF2f:
    mov ax,5A13h
    push ax
    mov ax,3DCh
    jmp short lblE7b
    nop
lblFCf:
    xor ax,ax
lblFEf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
