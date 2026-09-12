_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mf16:FAR
    EXTRN mf22:FAR
    EXTRN mf22:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    push word ptr [bp+6h]
    call mf9
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],ax
    mov ax,0F8h
    push ax
    call mf16
    add sp,2h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
