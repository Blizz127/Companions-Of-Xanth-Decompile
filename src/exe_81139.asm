_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf7:FAR
    EXTRN mf11:FAR
    EXTRN mf17:FAR
    EXTRN mf17:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf7
    add sp,4h
    mov ax,0h
    push ax
    call mf11
    add sp,2h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
