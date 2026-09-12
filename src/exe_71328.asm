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
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov ax,word ptr [bx+62BAh]
    les bx, dword ptr ds:[6DF4h]
    mov cx,word ptr es:[bx+2h]
    mov bx,word ptr es:[bx]
    add bx,ax
    mov ax,word ptr [bp+8h]
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx]
    jmp near ptr lbl2Cf
lbl2Cf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
