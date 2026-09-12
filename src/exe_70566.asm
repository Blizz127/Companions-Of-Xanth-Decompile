_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf13:FAR
    EXTRN mf16:FAR
    EXTRN mf23:FAR
    EXTRN mf23:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov al,byte ptr ds:[6288h]
    cbw
    cmp ax, offset mi7
    jnz short lbl15f
    jmp near ptr lbl2Af
lbl15f:
    cmp word ptr ds:[4176h],0h
    jnz short lbl1Ff
    jmp near ptr lbl24f
lbl1Ff:
    call mf13
lbl24f:
    mov ax,1h
    jmp near ptr lbl35f
lbl2Af:
    call mf16
    mov ax,0h
    jmp near ptr lbl35f
lbl35f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
