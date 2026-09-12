_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf11:FAR
    EXTRN mf12:FAR
    EXTRN mf17:FAR
    EXTRN mf17:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr [bp+6h]
    mov byte ptr ds:[5E78h],al
    mov ax,word ptr [bp+8h]
    mov byte ptr ds:[5E79h],al
    mov ax,word ptr [bp+0Ah]
    mov byte ptr ds:[5E7Ah],al
    call mf11
    call mf12
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
