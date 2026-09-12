_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN md19:NEAR
    EXTRN mf24:FAR
    EXTRN mf33:FAR
    EXTRN mf41:FAR
    EXTRN mi47:NEAR
    EXTRN mf60:FAR
    EXTRN mf67:FAR
    EXTRN mf78:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl70f
    jmp near ptr lblC8f
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lblC8f
lbl1Df:
    mov es, ds:[5B30h]
    mov bx,word ptr ds:[6A04h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md19],5h
    jnz short lbl48f
    push ax
    mov ax,11h
    push ax
    call mf24
    mov sp,bp
    push dx
    push ax
    mov ax,11h
    jmp short lbl5Df
lbl48f:
    push word ptr ds:[6A02h]
    mov ax,12h
    push ax
    call mf33
    add sp,4h
    push dx
    push ax
    mov ax,12h
lbl5Df:
    mov dx,0F02Fh
    push dx
    push ax
    call mf41
    add sp,8h
lbl6Ab:
    mov ax,1h
    jmp short lblCAf
    nop
lbl70f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi47
    jz short lblB2f
    ja short lblC8f
    sub al,8h
    jz short lbl8Cf
    sub al,0Bh
    jz short lbl9Af
    sub al,19h
    jz short lbl8Cf
    sub al,12h
    jz short lblACf
    jmp short lblC8f
lbl8Cf:
    push word ptr ds:[6A04h]
    call mf60
    add sp,2h
    jmp short lbl6Ab
lbl9Af:
    mov ax,0Fh
lbl9Db:
    mov dx,0F02Fh
    push dx
    push ax
    call mf67
    add sp,4h
    jmp short lbl6Ab
lblACf:
    mov ax,10h
    jmp short lbl9Db
    nop
lblB2f:
    xor ax,ax
    push ax
    mov ax,1ABh
    push ax
    push word ptr ds:[6A06h]
    call mf78
    add sp,6h
    jmp short lblCAf
    nop
lblC8f:
    xor ax,ax
lblCAf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
