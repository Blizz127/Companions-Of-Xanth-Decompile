_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf12:FAR
    EXTRN mi13:NEAR
    EXTRN mf16:FAR
    EXTRN mf21:FAR
    EXTRN mf21:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov es, ds:[5B44h]
    cmp word ptr es:[0h],0h
    jz short lbl18f
    jmp near ptr lbl23f
lbl18f:
    cmp word ptr es:[2h],0h
    jnz short lbl23f
    jmp near ptr lbl35f
lbl23f:
    call mf12
    cmp ax, offset mi13
    jz short lbl30f
    jmp near ptr lbl35f
lbl30f:
    call mf16
lbl35f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
