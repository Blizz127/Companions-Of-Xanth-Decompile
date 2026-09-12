_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf18:FAR
    EXTRN mf26:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov bx,word ptr [bp+6h]
    mov al,byte ptr [bx+5E44h]
    cbw
    push ax
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov ax,word ptr [bx+5E4Eh]
    push ax
    mov bx,word ptr [bp+6h]
    mov al,byte ptr [bx+5E3Ah]
    cbw
    push ax
    push word ptr [bp+6h]
    call mf18
    add sp,8h
    mov bx,word ptr [bp+6h]
    mov byte ptr [bx+5E60h],al
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
