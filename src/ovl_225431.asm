_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md13:NEAR
    EXTRN md18:NEAR
    EXTRN md19:NEAR
    EXTRN mf20:FAR
    EXTRN md30:NEAR
    EXTRN md31:NEAR
    EXTRN md35:NEAR
    EXTRN md36:NEAR
    EXTRN mf39:FAR
    EXTRN mf48:FAR
    EXTRN mf50:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    cmp word ptr ds:[5E10h],0h
    jnz short lbl10f
    jmp near ptr lbl9Bf
lbl10f:
    mov es, ds:[5B04h]
    dec word ptr ds:[5E10h]
    mov bx,word ptr ds:[5E10h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md13]
    mov word ptr [bp-2h],ax
    mov bx,ax
    add bx,ax
    add bx,bx
    push word ptr es:[bx+md18]
    push word ptr es:[bx+md19]
    call mf20
    add sp,4h
    xor ax,ax
    push ax
    mov es, ds:[5B04h]
    mov bx,word ptr ds:[5E10h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md30]
    mov dx,word ptr es:[bx+md31]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    mov word ptr es:[bx+md35],ax
    mov word ptr es:[bx+md36],dx
    push dx
    push ax
    call mf39
    add sp,6h
    inc word ptr ds:[5E0Ch]
    cmp word ptr ds:[5E10h],0h
    jnz short lbl96f
    mov ax,4h
    push ax
    xor ax,ax
    push ax
    call mf48
    add sp,4h
lbl96f:
    call mf50
lbl9Bf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
