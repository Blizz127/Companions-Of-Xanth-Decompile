_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md11:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push di
    push si
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov cl,3h
    mov bx,word ptr ds:[74h]
    shl bx,cl
    mov es, ds:[5A1Eh]
    push ds
    lea di,word ptr [bx+md11]
    mov si,ax
    mov ds,dx
    movsw
    movsw
    movsw
    movsw
    pop ds
    inc word ptr ds:[74h]
    cmp word ptr ds:[74h],4h
    jc short lbl36f
    mov word ptr ds:[74h],0h
lbl36f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
