_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf5:FAR
    EXTRN mf6:FAR
    EXTRN mf8:FAR
    EXTRN mf11:FAR
    EXTRN mf14:FAR
    EXTRN mf17:FAR
    EXTRN mf20:FAR
    EXTRN mf23:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    call mf5
    call mf6
    push word ptr [bp+6h]
    call mf8
    add sp,2h
    push word ptr [bp+6h]
    call mf11
    add sp,2h
    push word ptr [bp+6h]
    call mf14
    add sp,2h
    push word ptr [bp+6h]
    call mf17
    add sp,2h
    push word ptr [bp+6h]
    call mf20
    add sp,2h
    push word ptr [bp+6h]
    call mf23
    add sp,2h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
