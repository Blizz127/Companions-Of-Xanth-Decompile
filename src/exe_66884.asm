_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf16:FAR
    EXTRN mf22:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov al,byte ptr ds:[5E7Ah]
    cbw
    cmp ax, offset mi7
    jnz short lbl15f
    jmp near ptr lbl1Bf
lbl15f:
    mov ax,40h
    jmp near ptr lbl1Ef
lbl1Bf:
    mov ax,0h
lbl1Ef:
    push ax
    mov ax,8h
    push ax
    call mf16
    add sp,4h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
