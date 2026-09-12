_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mi11:NEAR
    EXTRN mf15:FAR
    EXTRN mf18:FAR
    EXTRN mi20:NEAR
    EXTRN mf26:FAR
    EXTRN mf30:FAR
    EXTRN mf34:FAR
    EXTRN mf38:FAR
    EXTRN mf42:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[4172h]
    push ax
    mov ax,word ptr ds:[4174h]
    push ax
    call mf9
    add sp,4h
    cmp ax, offset mi11
    jz short lbl21f
    jmp near ptr lbl24f
lbl21f:
    jmp near ptr lbl7Cf
lbl24f:
    call mf15
lbl29b:
    mov ax,3Fh
    push ax
    call mf18
    add sp,2h
    cmp ax, offset mi20
    jz short lbl3Df
    jmp near ptr lbl40f
lbl3Df:
    jmp near ptr lbl29b
lbl40f:
    mov ax,0F0h
    push ax
    call mf26
    add sp,2h
    mov ax,41h
    push ax
    call mf30
    add sp,2h
    mov ax,10h
    push ax
    call mf34
    add sp,2h
    mov ax,16h
    push ax
    call mf38
    add sp,2h
    mov ax,12h
    push ax
    call mf42
    add sp,2h
lbl7Cf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
