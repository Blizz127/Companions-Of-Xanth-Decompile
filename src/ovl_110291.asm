_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf20:FAR
    EXTRN mf28:FAR
    EXTRN mi33:NEAR
    EXTRN mf63:FAR
    EXTRN mf67:FAR
    EXTRN mf73:FAR
    EXTRN mf89:FAR
    EXTRN mf94:FAR
    EXTRN mf98:FAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl4Ef
    jmp near ptr lbl10Cf
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lbl10Cf
lbl1Df:
    mov ax,word ptr ds:[6A04h]
    sub ax,90h
    jz short lbl28f
    jmp near ptr lbl10Cf
lbl28f:
    push word ptr ds:[6A02h]
    mov ax,13h
    push ax
    call mf20
    mov sp,bp
    push dx
    push ax
    mov ax,1Eh
lbl3Cb:
    mov dx,0F00Ah
    push dx
    push ax
    call mf28
lbl46b:
    mov sp,bp
lbl48b:
    mov ax,1h
    jmp near ptr lbl10Ef
lbl4Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi33
    jz short lbl86f
    jna short lbl5Bf
    jmp near ptr lbl10Cf
lbl5Bf:
    cmp al,13h
    jnz short lbl62f
    jmp near ptr lbl100f
lbl62f:
    ja short lbl72f
    sub al,7h
    jz short lbl86f
    dec al
    jnz short lbl6Ff
    jmp near ptr lblFAf
lbl6Ff:
    jmp near ptr lbl10Cf
lbl72f:
    sub al,2Ch
    jnz short lbl79f
    jmp near ptr lblFAf
lbl79f:
    sub al,19h
    jnz short lbl80f
    jmp near ptr lbl106f
lbl80f:
    jmp near ptr lbl10Cf
    nop
    nop
    nop
lbl86f:
    cmp byte ptr ds:[30Fh],0h
    jnz short lblBEf
    mov ax,18h
    mov dx,0F00Ah
    push dx
    push ax
    call mf63
    mov sp,bp
    mov ax,0FA0h
    push ax
    call mf67
    mov sp,bp
    mov ax,5A03h
    push ax
    mov ax,11Ch
    push ax
    call mf73
    mov sp,bp
    mov byte ptr ds:[30Fh],1h
    jmp short lbl48b
    nop
lblBEf:
    cmp byte ptr ds:[2F3h],0h
    jz short lblCAf
    mov ax,1Ah
    jmp short lblCDf
lblCAf:
    mov ax,1Bh
lblCDf:
    mov dx,0F00Ah
    push dx
    push ax
    mov ax,19h
    push dx
    push ax
    call mf89
    mov sp,bp
    mov word ptr ds:[2A8h],4h
    xor ax,ax
    push ax
    call mf94
    mov sp,bp
    mov ax,5Ah
    push ax
    call mf98
    jmp near ptr lbl46b
lblFAf:
    mov ax,1Ch
    jmp near ptr lbl3Cb
lbl100f:
    mov ax,17h
    jmp near ptr lbl3Cb
lbl106f:
    mov ax,1Dh
    jmp near ptr lbl3Cb
lbl10Cf:
    xor ax,ax
lbl10Ef:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
