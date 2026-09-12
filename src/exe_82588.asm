_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mf14:FAR
    EXTRN mf20:FAR
    EXTRN mf26:FAR
    EXTRN mf35:FAR
    EXTRN mf35:FAR
    EXTRN mf35:FAR
    EXTRN mf35:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[4234h],0h
    jnz short lbl13f
    jmp near ptr lbl25f
lbl13f:
    push word ptr ds:[4234h]
    call mf9
    add sp,2h
    mov word ptr ds:[4234h],0h
lbl25f:
    push word ptr ds:[423Eh]
    push word ptr ds:[423Ch]
    call mf14
    add sp,4h
    mov word ptr ds:[423Ch],0h
    mov word ptr ds:[423Eh],0h
    push word ptr ds:[4242h]
    push word ptr ds:[4240h]
    call mf20
    add sp,4h
    mov word ptr ds:[4240h],0h
    mov word ptr ds:[4242h],0h
    push word ptr ds:[423Ah]
    push word ptr ds:[4238h]
    call mf26
    add sp,4h
    mov word ptr ds:[4238h],0h
    mov word ptr ds:[423Ah],0h
    mov word ptr ds:[4232h],0h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
