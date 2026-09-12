_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov di,ax
    mov ax,3000h
    int 21h
    cmp al,3h
    jnc short lbl17f
    stc
    pop bp
    pop es
    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    retf
lbl17f:
_TEXT ENDS
    END
