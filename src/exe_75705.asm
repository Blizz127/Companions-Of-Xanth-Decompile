_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf7:FAR
    EXTRN mf9:FAR
    EXTRN mf14:FAR
    EXTRN mf14:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,0F7h
    push ax
    call mf7
    add sp,2h
    call mf9
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
