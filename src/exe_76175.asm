_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf12:FAR
    EXTRN mf22:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[416Eh]
    and ax,80h
    cmp ax, offset mi7
    jz short lbl17f
    jmp near ptr lbl44f
lbl17f:
    mov ax,8h
    push ax
    call mf12
    add sp,2h
    mov word ptr ds:[6DF8h],ax
    mov word ptr ds:[6DFAh],dx
    mov ax,9FB3h
    mov dx,8A7h
    push dx
    push ax
    mov ax,8h
    push ax
    call mf22
    add sp,6h
    or word ptr ds:[416Eh],80h
lbl44f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
