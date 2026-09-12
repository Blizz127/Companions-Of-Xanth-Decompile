_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf20:FAR
    EXTRN mf26:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[416Eh]
    and ax,80h
    cmp ax, offset mi7
    jnz short lbl17f
    jmp near ptr lbl44f
lbl17f:
    and word ptr ds:[416Eh],0FF7Fh
    mov word ptr ds:[418Ch],0h
    jmp near ptr lbl26f
lbl26b:
lbl26f:
    cmp word ptr ds:[418Ah],0h
    jz short lbl30f
    jmp near ptr lbl26b
lbl30f:
    push word ptr ds:[6DFAh]
    push word ptr ds:[6DF8h]
    mov ax,8h
    push ax
    call mf20
    add sp,6h
lbl44f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
