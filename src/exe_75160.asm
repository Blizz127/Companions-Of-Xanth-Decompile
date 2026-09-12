_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf8:FAR
    EXTRN mf22:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr ds:[6DF2h],0h
    mov word ptr ds:[411Eh],1h
    jmp near ptr lbl1Df
lbl18b:
    call mf8
lbl1Df:
    cmp word ptr ds:[411Eh],0h
    jz short lbl27f
    jmp near ptr lbl18b
lbl27f:
    cmp word ptr ds:[411Ah],0h
    jnz short lbl31f
    jmp near ptr lbl37f
lbl31f:
    mov word ptr ds:[411Ah],0h
lbl37f:
    mov ax,1h
    jmp near ptr lbl3Df
lbl3Df:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
