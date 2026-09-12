_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf16:FAR
    EXTRN mf23:FAR
    EXTRN mf31:FAR
    EXTRN mi36:NEAR
    EXTRN mf47:FAR
    EXTRN mf56:FAR
    EXTRN mf65:FAR
    EXTRN mf75:FAR
    EXTRN mf75:FAR
    EXTRN mf75:FAR
    EXTRN mf75:FAR
    EXTRN mf75:FAR
    EXTRN mf75:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl54f
    jmp near ptr lblACf
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lblACf
lbl1Df:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf16
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf23
    add sp,4h
    push dx
    push ax
    mov ax,0Fh
lbl43b:
    mov dx,0F02Eh
    push dx
    push ax
    call mf31
    mov sp,bp
    mov ax,1h
    jmp short lblAEf
lbl54f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi36
    jz short lbl94f
    ja short lblACf
    sub al,13h
    jz short lbl68f
    sub al,19h
    jz short lbl7Ef
    jmp short lblACf
lbl68f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf47
    mov sp,bp
    push dx
    push ax
    mov ax,0Ch
    jmp short lbl43b
lbl7Ef:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf56
    mov sp,bp
    push dx
    push ax
    mov ax,0Dh
    jmp short lbl43b
lbl94f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf65
    add sp,4h
    push dx
    push ax
    mov ax,0Eh
    jmp short lbl43b
    nop
lblACf:
    xor ax,ax
lblAEf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
