_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf16:FAR
    EXTRN mf24:FAR
    EXTRN mi31:NEAR
    EXTRN mf54:FAR
    EXTRN mf56:FAR
    EXTRN mf61:FAR
    EXTRN mf71:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl44f
    jmp near ptr lblACf
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lblACf
lbl1Df:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf16
    mov sp,bp
    push dx
    push ax
    mov ax,4Ah
lbl31b:
    mov dx,0F049h
    push dx
    push ax
    call mf24
lbl3Bb:
    mov sp,bp
lbl3Db:
    mov ax,1h
    jmp short lblAEf
    nop
    nop
lbl44f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi31
    jz short lblA0f
    ja short lblACf
    cmp al,2Ch
    jz short lbl68f
    ja short lbl5Ef
    sub al,8h
    jz short lbl68f
    sub al,0Bh
    jz short lbl6Ef
    jmp short lblACf
lbl5Ef:
    sub al,3Fh
    jz short lbl84f
    sub al,5h
    jz short lbl9Af
    jmp short lblACf
lbl68f:
    mov ax,48h
    jmp short lbl31b
    nop
lbl6Ef:
    mov ax,46h
lbl71b:
    mov dx,0F049h
    push dx
    push ax
    call mf54
    mov sp,bp
    call mf56
    jmp short lbl3Db
lbl84f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf61
    mov sp,bp
    push dx
    push ax
    mov ax,49h
    jmp short lbl71b
lbl9Af:
    mov ax,47h
    jmp short lbl31b
    nop
lblA0f:
    push word ptr ds:[6A04h]
    call mf71
    jmp short lbl3Bb
    nop
lblACf:
    xor ax,ax
lblAEf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
