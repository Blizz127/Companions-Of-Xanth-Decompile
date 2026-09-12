_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf5:FAR
    EXTRN mi6:NEAR
    EXTRN mf10:FAR
    EXTRN mf24:FAR
    EXTRN mf24:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    call mf5
    add ax, offset mi6
    adc dx,0h
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
lbl1Ab:
    call mf10
    cmp dx,word ptr [bp-4h]
    jng short lbl27f
    jmp near ptr lbl37f
lbl27f:
    jnl short lbl2Cf
    jmp near ptr lbl34f
lbl2Cf:
    cmp ax,word ptr [bp-6h]
    jc short lbl34f
    jmp near ptr lbl37f
lbl34f:
    jmp near ptr lbl1Ab
lbl37f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
