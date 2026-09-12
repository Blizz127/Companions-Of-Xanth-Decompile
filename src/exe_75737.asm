_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf5:FAR
    EXTRN mf8:FAR
    EXTRN mf12:FAR
    EXTRN mf16:FAR
    EXTRN mf20:FAR
    EXTRN mf24:FAR
    EXTRN mf26:FAR
    EXTRN mf27:FAR
    EXTRN mf32:FAR
    EXTRN mf32:FAR
    EXTRN mf32:FAR
    EXTRN mf32:FAR
    EXTRN mf32:FAR
    EXTRN mf32:FAR
    EXTRN mf32:FAR
    EXTRN mf32:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    call mf5
    mov ax,7Fh
    push ax
    call mf8
    add sp,2h
    mov ax,0h
    push ax
    call mf12
    add sp,2h
    mov ax,0h
    push ax
    call mf16
    add sp,2h
    mov ax,0h
    push ax
    call mf20
    add sp,2h
    mov ax,1h
    push ax
    call mf24
    add sp,2h
    call mf26
    call mf27
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
