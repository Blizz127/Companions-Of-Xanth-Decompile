_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi7:NEAR
    EXTRN mf30:FAR
    EXTRN mf38:FAR
    EXTRN mf48:FAR
    EXTRN mf50:FAR
    EXTRN mf53:FAR
    EXTRN mf55:FAR
    EXTRN mf59:FAR
    EXTRN mf66:FAR
    EXTRN mf73:FAR
    EXTRN mf78:FAR
    EXTRN mf85:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl0Ef
    jmp near ptr lblE0f
lbl0Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi7
    jnz short lbl19f
    jmp near ptr lblD8f
lbl19f:
    jna short lbl1Ef
    jmp near ptr lblE0f
lbl1Ef:
    cmp al,2Ch
    jz short lbl3Ef
    ja short lbl30f
    sub al,8h
    jz short lbl3Ef
    sub al,0Bh
    jz short lbl64f
    jmp near ptr lblE0f
    nop
lbl30f:
    sub al,3Ah
    jz short lbl64f
    sub al,0Ah
    jnz short lbl3Bf
    jmp near ptr lblC0f
lbl3Bf:
    jmp near ptr lblE0f
lbl3Ef:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf30
    mov sp,bp
    push dx
    push ax
    mov ax,19h
lbl52b:
    mov dx,0F003h
    push dx
    push ax
    call mf38
lbl5Cb:
    mov sp,bp
lbl5Eb:
    mov ax,1h
    jmp short lblE2f
    nop
lbl64f:
    cmp byte ptr ds:[323h],0h
    jnz short lbl70f
    mov byte ptr ds:[323h],1h
lbl70f:
    mov ax,20Ah
    push ax
    call mf48
    mov sp,bp
    call mf50
    xor ax,ax
    push ax
    call mf53
    mov sp,bp
    call mf55
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf59
    mov sp,bp
    or ax,ax
    jnz short lbl5Eb
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf66
    mov sp,bp
    xor ax,ax
    push ax
    push ax
    mov ax,5h
    push ax
    call mf73
    jmp short lbl5Cb
lblC0f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf78
    mov sp,bp
    push dx
    push ax
    mov ax,18h
    jmp near ptr lbl52b
    nop
lblD8f:
    call mf85
    jmp near ptr lbl5Eb
lblE0f:
    xor ax,ax
lblE2f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
