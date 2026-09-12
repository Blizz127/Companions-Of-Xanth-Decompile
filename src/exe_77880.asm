_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi12:NEAR
    EXTRN mi13:NEAR
    EXTRN mi17:NEAR
    EXTRN mi18:NEAR
    EXTRN mf21:FAR
    EXTRN mi25:NEAR
    EXTRN mi26:NEAR
    EXTRN mf29:FAR
    EXTRN mf46:FAR
    EXTRN mf46:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[418Eh],0h
    jnz short lbl13f
    jmp near ptr lbl19f
lbl13f:
    mov ax,1h
    jmp near ptr lbl84f
lbl19f:
    add word ptr ds:[418Eh],1h
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi12
    cmp ax, offset mi13
    jnz short lbl2Cf
    jmp near ptr lbl79f
lbl2Cf:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi17
    cmp ax, offset mi18
    jnz short lbl3Af
    jmp near ptr lbl45f
lbl3Af:
    call mf21
    mov word ptr [bp-4h],ax
    jmp near ptr lbl63f
lbl45f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi25
    cmp ax, offset mi26
    jnz short lbl53f
    jmp near ptr lbl5Ef
lbl53f:
    call mf29
    mov word ptr [bp-4h],ax
    jmp near ptr lbl63f
lbl5Ef:
    mov word ptr [bp-4h],0h
lbl63f:
    cmp word ptr [bp-4h],0h
    jnz short lbl6Cf
    jmp near ptr lbl74f
lbl6Cf:
    or word ptr ds:[416Eh],40h
    jmp near ptr lbl79f
lbl74f:
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFF8Fh
lbl79f:
    sub word ptr ds:[418Eh],1h
    mov ax,word ptr [bp-4h]
    jmp near ptr lbl84f
lbl84f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
