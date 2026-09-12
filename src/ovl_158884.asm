_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi14:NEAR
    EXTRN mi18:NEAR
    EXTRN mf28:FAR
    EXTRN mi33:NEAR
    EXTRN mi35:NEAR
    EXTRN mf54:FAR
    EXTRN mf63:FAR
    EXTRN mf71:FAR
    EXTRN mf78:FAR
    EXTRN mf91:FAR
    EXTRN mf99:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi3
    jz short lbl48f
    jna short lbl10f
    jmp near ptr lbl10Af
lbl10f:
    sub al,4h
    jz short lbl1Cf
    sub al,2h
    jz short lbl4Ef
    jmp near ptr lbl10Af
    nop
lbl1Cf:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi14
    jz short lbl27f
    jmp near ptr lbl10Af
lbl27f:
    mov ax,word ptr ds:[6A04h]
    sub ax, offset mi18
    jz short lbl38f
    mov ax,5A01h
    push ax
    mov ax,2C0h
    jmp short lbl3Ff
lbl38f:
    mov ax,5A01h
    push ax
    mov ax,2E3h
lbl3Fb:
lbl3Ff:
    push ax
    call mf28
lbl45b:
    add sp,4h
lbl48b:
lbl48f:
    mov ax,1h
    jmp near ptr lbl10Cf
lbl4Ef:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi33
    jz short lbl5Ef
    sub ax, offset mi35
    jz short lbl64f
    jmp near ptr lbl10Af
lbl5Ef:
    mov ax,13h
    jmp short lblADf
    nop
lbl64f:
    cmp word ptr ds:[290h],0h
    jnz short lbl74f
    mov ax,5A01h
    push ax
    mov ax,29Ah
    jmp short lbl3Fb
lbl74f:
    cmp word ptr ds:[256h],5Bh
    jnz short lbl9Af
    mov byte ptr ds:[1D00h],0h
    mov ax,5A01h
    push ax
    mov ax,29Ch
    push ax
    call mf54
    add sp,4h
    mov ax,5A06h
    push ax
    mov ax,2D2h
    jmp short lbl3Fb
    nop
lbl9Af:
    mov ax,24h
    push ax
    call mf63
    add sp,2h
    or ax,ax
    jz short lblBAf
    mov ax,14h
lblADf:
    mov dx,0F006h
    push dx
    push ax
    call mf71
    jmp short lbl45b
    nop
lblBAf:
    mov ax,5A01h
    push ax
    mov ax,29Bh
    push ax
    call mf78
    add sp,4h
    cmp word ptr ds:[256h],180h
    jz short lblD5f
    jmp near ptr lbl48b
lblD5f:
    cmp byte ptr ds:[373h],0h
    jnz short lblDFf
    jmp near ptr lbl48b
lblDFf:
    mov byte ptr ds:[373h],0h
    mov ax,15h
    mov dx,0F006h
    push dx
    push ax
    call mf91
    add sp,4h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,6h
    push ax
    call mf99
    add sp,6h
    jmp near ptr lbl48b
lbl10Af:
    xor ax,ax
lbl10Cf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
