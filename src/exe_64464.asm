_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf6:FAR
    EXTRN mf8:FAR
    EXTRN mf15:FAR
    EXTRN mf15:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr ds:[6DE0h],388h
    call mf6
    mov word ptr [bp-4h],ax
    call mf8
    mov ax,word ptr [bp-4h]
    jmp near ptr lbl22f
lbl22f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
