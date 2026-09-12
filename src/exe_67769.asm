_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf11:FAR
    EXTRN mf17:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov al,byte ptr ds:[40F8h]
    cbw
    cmp ax, offset mi7
    jnz short lbl15f
    jmp near ptr lbl18f
lbl15f:
    jmp near ptr lbl22f
lbl18f:
    call mf11
    mov byte ptr ds:[40F8h],1h
lbl22f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
