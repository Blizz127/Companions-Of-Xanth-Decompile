_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf13:FAR
    EXTRN mf17:FAR
    EXTRN mf19:FAR
    EXTRN mf24:FAR
    EXTRN mf24:FAR
    EXTRN mf24:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov byte ptr ds:[6284h],0h
    mov byte ptr ds:[6288h],1h
    mov ax,0A120h
    mov dx,7h
    push dx
    push ax
    mov ax,0h
    push ax
    call mf13
    add sp,6h
    mov ax,1h
    push ax
    call mf17
    add sp,2h
    call mf19
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
