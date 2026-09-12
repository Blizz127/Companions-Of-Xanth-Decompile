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
    mov ax,word ptr ds:[627Ch]
    les bx, dword ptr ds:[6DE6h]
    mov cx,word ptr es:[bx+2h]
    mov bx,word ptr es:[bx]
    add bx,ax
    mov ax,word ptr [bp+6h]
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx]
    jmp near ptr lbl26f
lbl26f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
