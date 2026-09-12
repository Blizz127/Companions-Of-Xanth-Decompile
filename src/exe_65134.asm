_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr [bp+6h],0Ch
    ja short lbl12f
    jmp near ptr lbl17f
lbl12f:
    mov word ptr [bp+6h],0Ch
lbl17f:
    cmp word ptr [bp+6h],1h
    jc short lbl20f
    jmp near ptr lbl25f
lbl20f:
    mov word ptr [bp+6h],1h
lbl25f:
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[6DE2h],ax
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
