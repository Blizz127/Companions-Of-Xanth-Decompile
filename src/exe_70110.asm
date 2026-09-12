_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf5:FAR
    EXTRN mf15:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    call mf5
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    add word ptr ds:[627Ch],ax
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
