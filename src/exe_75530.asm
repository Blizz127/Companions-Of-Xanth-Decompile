_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mf12:FAR
    EXTRN mf19:FAR
    EXTRN mf19:FAR
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
    mov word ptr [bp-4h],ax
    call mf12
    mov ax,word ptr [bp-4h]
    jmp near ptr lbl27f
lbl27f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
