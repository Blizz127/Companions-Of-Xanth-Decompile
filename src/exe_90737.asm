_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf19:FAR
    EXTRN mf24:FAR
    EXTRN mf29:FAR
    EXTRN mf29:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    mov word ptr ds:[4D3Ah],0h
    mov ax,0FFFFh
    mov cx,8h
    mov di,6354h
    push ds
    pop es
    rep stosw
    xor ax,ax
    push ax
    push word ptr [bp+6h]
    mov ax,5h
    push ax
    mov ax,4D3Ch
    push ds
    push ax
    call mf19
    add sp,0Ah
    mov ax,4D3Ch
    push ds
    push ax
    call mf24
    add sp,4h
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
