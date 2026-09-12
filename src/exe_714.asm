_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf9:FAR
mnem_unit:
    push bp
    mov bp,sp
    push di
    push si
    mov ah,byte ptr [bp+6h]
    call mf5
    pop si
    pop di
    pop bp
    retf
_TEXT ENDS
    END
